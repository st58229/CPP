#include "TimeOrder.h"

void TimeOrder::Order(IComparable** field, int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (field[i]->compareTo(field[j]) == -1) {
				IComparable* temp = field[i];
				field[i] = field[j];
				field[j] = temp;
			}
		}
	}
}
