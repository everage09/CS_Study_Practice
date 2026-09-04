#pragma once

template <typename T>
int BinarySearchRec(T* list, T target, int fromLoc, int toLoc)
{
	if (fromLoc > toLoc) return -1;
	int mid = (fromLoc + toLoc) / 2;
	if (list[mid] == target) return mid;
	else if (list[mid] < target) return BinarySearchRec(list, target, mid + 1, toLoc);
	else return BinarySearchRec(list, target, fromLoc, mid - 1);
}