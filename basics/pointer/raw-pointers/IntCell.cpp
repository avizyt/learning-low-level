#include "IntCell.h"

/**
Construct the IntCell with initialValue
*/

IntCell::IntCell(int initialValue) : storeValue{initialValue} {}

/**
Return the stored value. */

int IntCell::read() const { return storeValue; }

/**
Store x. */

void IntCell::write(int x) { storeValue = x; }