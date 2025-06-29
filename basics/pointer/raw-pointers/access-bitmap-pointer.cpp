

#include <cstdint>
#include <iostream>
#include <vector>
const int IMAGE_WIDTH = 50;
const int IMAGE_HEIGHT = 10;

int main() {
  // creating bitmap image in memory
  std::vector<uint8_t> bitmap_data(IMAGE_WIDTH * IMAGE_HEIGHT);
  uint8_t *pixel_ptr = bitmap_data.data();

  for (int r = 0; r < IMAGE_HEIGHT; ++r) {
    for (int c = 0; c < IMAGE_WIDTH; ++c) {
      // create a single horizontal grad
      bitmap_data[r * IMAGE_WIDTH + c] =
          static_cast<uint8_t>((c / (double)IMAGE_WIDTH) * 255);
    }
  }

  std::cout << "--- Intial Bitmap (first 3 rows) ---" << "\n";
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < IMAGE_WIDTH; ++c) {
      // print a char repr of intensity
      char displau_char = ' ';
      uint8_t pixel_val = bitmap_data[r * IMAGE_WIDTH + c];
      if (pixel_val > 200)
        displau_char = '#';
      else if (pixel_val > 155)
        displau_char = '*';
      else if (pixel_val > 100)
        displau_char = '+';
      else if (pixel_val > 50)
        displau_char = '.';

      std::cout << displau_char;
    }
    std::cout << "\n";
  }
  std::cout << "\n";

  // -----------------------------------------------------------
  // 3. Demonstrate Accessing Pixels using Pointer Arithmetic
  // -----------------------------------------------------------

  // Access pixel at (row 2, column 5)
  int target_row1 = 2;
  int target_col1 = 5;
  uint8_t *pixel_address1 =
      pixel_ptr + (target_row1 * IMAGE_WIDTH + target_col1);
  uint8_t pixel_value1 = *pixel_address1;

  std::cout << "Pixel at (" << target_row1 << ", " << target_col1
            << ") using pointer arithmetic: " << (int)pixel_value1
            << std::endl; // Cast to int to print numeric value

  // Access pixel at (row 7, column 25)
  int target_row2 = 7;
  int target_col2 = 25;
  uint8_t *pixel_address2 =
      pixel_ptr + (target_row2 * IMAGE_WIDTH + target_col2);
  uint8_t pixel_value2 = *pixel_address2;

  std::cout << "Pixel at (" << target_row2 << ", " << target_col2
            << ") using pointer arithmetic: " << (int)pixel_value2 << std::endl;

  // -----------------------------------------------------------
  // 4. Demonstrate Modifying Pixels using Pointer Arithmetic
  //    Let's draw a simple cross in the middle of the image.
  // -----------------------------------------------------------
  std::cout << "\n--- Modifying Pixels (Drawing a Cross) ---" << std::endl;

  int center_row = IMAGE_HEIGHT / 2;
  int center_col = IMAGE_WIDTH / 2;
  uint8_t new_color = 255; // White (max intensity)

  // Draw horizontal line
  for (int c = center_col - 5; c <= center_col + 5; ++c) {
    if (c >= 0 && c < IMAGE_WIDTH) {
      uint8_t *current_pixel_address =
          pixel_ptr + (center_row * IMAGE_WIDTH + c);
      *current_pixel_address = new_color;
    }
  }

  // Draw vertical line
  for (int r = center_row - 2; r <= center_row + 2; ++r) {
    if (r >= 0 && r < IMAGE_HEIGHT) {
      uint8_t *current_pixel_address =
          pixel_ptr + (r * IMAGE_WIDTH + center_col);
      *current_pixel_address = new_color;
    }
  }

  // -----------------------------------------------------------
  // 5. Print the Modified Bitmap (first 3 rows and then a couple around center)
  // -----------------------------------------------------------
  std::cout << "\n--- Modified Bitmap (showing cross) ---" << std::endl;
  for (int r = 0; r < IMAGE_HEIGHT;
       ++r) { // Print entire image for full view of cross
    for (int c = 0; c < IMAGE_WIDTH; ++c) {
      char display_char = ' ';
      uint8_t pixel_val =
          *(pixel_ptr + (r * IMAGE_WIDTH + c)); // Using pointer arithmetic here
      if (pixel_val > 200)
        display_char = '#';
      else if (pixel_val > 150)
        display_char = '*';
      else if (pixel_val > 100)
        display_char = '+';
      else if (pixel_val > 50)
        display_char = '.';
      std::cout << display_char;
    }
    std::cout << std::endl;
  }

  return 0;
}

/*
Explanation

1. bitmap_data.data(): This std::vector method returns a raw pointer (uint8_t*
in this case) to the beginning of the contiguous memory block that the vector
manages. This is the starting point for all our pointer arithmetic.

2. pixel_ptr + (row * IMAGE_WIDTH + col): This is the core of accessing any
pixel.

    - (row * IMAGE_WIDTH): Calculates the offset to the beginning of the desired
row.

    - + col: Adds the offset within that row to reach the specific column.

    - The sum (row * IMAGE_WIDTH + col) is the total number of uint8_t elements
    (bytes) from the start of the pixel_ptr to the desired pixel.

    - When you add an integer N to a pointer P of type T*, the result is a
pointer P + N that points N * sizeof(T) bytes away from P. In our case,
sizeof(uint8_t) is 1, so N directly corresponds to bytes.

3. *pixel_address: The dereference operator * is used to get the value stored at
the memory location pointed to by pixel_address.

4. *current_pixel_address = new_color;: Similarly, to modify the pixel, you
dereference the calculated pixel address and assign a new value to it.

*/