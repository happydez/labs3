#pragma once

#include <iostream>
#include <chrono>
#include <ctime>
#include <random>

using namespace std;

static class ArrayInstance
{
	public:

		static enum GenerationType
		{
			None,
			Unsorted,
			Semisorted,
			Sorted,
			Repeatsorted,
		};

		static enum SortType
		{
			Quick,
			Shell,
			Tim,
		};

		static void SortTime(int arr[], int n, SortType st, GenerationType gt = None)
		{
			chrono::time_point<chrono::system_clock> start, end;

			start = chrono::system_clock::now();

			switch (st)
			{
				case ArrayInstance::Quick:
				{
					QuickSort(arr, 0, n - 1);
					break;
				}
				case ArrayInstance::Shell:
				{
					ShellSort(arr, n);
					break;
				}
				case ArrayInstance::Tim:
				{
					TimSort(arr, n);
					break;
				}
			}

			end = chrono::system_clock::now();

			chrono::duration<double> elapsed_seconds = end - start;
			time_t end_time = chrono::system_clock::to_time_t(end);

			cout << string('-', 32) << endl;
			cout << "n = " << n << endl;

			if (gt != GenerationType::None)
			{
				cout << "array type: " << ((gt == GenerationType::Sorted) ? "sorted"
					: (gt == GenerationType::Unsorted ? "unsorted"
					: (gt == GenerationType::Semisorted ? "semisorted" : "repeatsorted"))) << endl;
			}

			cout << "sort type: " << ((st == SortType::Quick) ? "quick sort" : (st == SortType::Shell ? "shell sort" : "tim sort")) << endl;
			cout << "elapsed time: " << elapsed_seconds.count() << endl;
			cout << string('-', 32) << endl;
		}

		static int* Generate(int n, GenerationType gt)
		{
			if (n <= 0)
			{
				return nullptr;
			}

			int* arr = new int[n];

			for (int i = 0; i < n; i++)
			{
				switch (gt)
				{
					case ArrayInstance::Unsorted:
					{
						arr[i] = n - i - 1;
						break;
					}
					case ArrayInstance::Semisorted:
					{
						random_device rd;
						mt19937 gen(rd());
						uniform_int_distribution<> dist(1, n);

						for (int j = 0; j < n / 2; j++) arr[j] = j + 1;
						for (int j = n / 2; j < n; j++) arr[j] = dist(gen);

						i = n;

						break;
					}
					case ArrayInstance::Sorted:
					{
						arr[i] = i;
						break;
					}
					case ArrayInstance::Repeatsorted:
					{
						int k = 5;
						for (int j = 0; j < n; j++) arr[j] = (j + 1) % k;
						break;
					}
				}
			}

			return arr;
		}

		// Time complexity
		// Best:  O(nlog(n))
		// Avg:   O(nlog(n))
		// Worst: O(n^2)
		// ----------------------
		// Space complexity: O(log(n))
		// ----------------------
		// Unstable
		static void QuickSort(int* arr, int l, int r)
		{
			if (r - l <= 0)
			{
				return;
			}

			int i = l, j = r;
			int x = arr[(l + j) / 2];

			while (i <= j)
			{
				while (arr[i] < x) i++;
				while (arr[j] > x) j--;

				if (i <= j)
				{
					swap(arr[i], arr[j]);
					i++; j--;
				}
			}

			if (i < r) QuickSort(arr, i, r);
			if (l < j) QuickSort(arr, l, j);
		}

		// Time complexity
		// Best:  O(nlog(n))
		// Avg:   O(n(log(n)^2))
		// Worst: O(n(log(n)^2))
		// ----------------------
		// Space complexity: O(1)
		// ----------------------
		// Unstable
		static void ShellSort(int* arr, int n)
		{
			for (int step = n / 2; step > 0; step /= 2)
			{
				for (int i = step; i < n; i++)
				{
					int temp = arr[i];

					int j = i;
					for (j; j >= step && arr[j - step] > temp; j -= step)
					{
						arr[j] = arr[j - step];
					}

					arr[j] = temp;
				}
			}
		}

		// Time complexity
		// Best:  O(n)
		// Avg:   O(nlog(n))
		// Worst: O(nlog(n))
		// ----------------------
		// Space complexity: O(n)
		// ----------------------
		// Stable
		static void TimSort(int* arr, int n)
		{
			timsort(arr, n);
		}

		static void Print(const int* arr, int n, string msg = "")
		{
			cout << msg;

			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}

			cout << endl;
		}

	private:

		static int calcMinRun(int length) {
			int r = 0;
			while (length >= 32) {
				r |= length & 1;
				length >>= 1;
			}

			return length + r;
		}

		static void insertionSort(int* arr, int left, int right) {
			for (int i = left + 1; i < right + 1; i++) {
				int j = i;
				while (j > left && arr[j] < arr[j - 1]) {
					swap(arr[j], arr[j - 1]);
					j--;
				}
			}
		}

		static void merge(int* arr, int left, int middle, int right) {
			int len1 = middle - left + 1, len2 = right - middle;
			int* leftArr = new int[len1];
			int* rightArr = new int[len2];

			for (int i = 0; i < len1; i++) {
				leftArr[i] = arr[left + i];
			}

			for (int i = 0; i < len2; i++) {
				rightArr[i] = arr[middle + 1 + i];
			}

			int i = 0, j = 0, k = left;
			while (i < len1 && j < len2) {
				if (leftArr[i] <= rightArr[j]) {
					arr[k] = leftArr[i];
					i++;
				}
				else {
					arr[k] = rightArr[j];
					j++;
				}
				k++;
			}

			while (i < len1) {
				arr[k] = leftArr[i];
				k++;
				i++;
			}

			while (j < len2) {
				arr[k] = rightArr[j];
				k++;
				j++;
			}
		}

		static void timsort(int* arr, int len) {
			int minRun = calcMinRun(len);

			for (int start = 0; start < len; start += minRun) {
				int end = std::min(start + minRun - 1, len - 1);
				insertionSort(arr, start, end);
			}

			int size = minRun;
			while (size < len) {
				for (int left = 0; left < len; left += 2 * size) {
					int middle = std::min(len - 1, left + size - 1);
					int right = std::min(left + 2 * size - 1, len - 1);

					if (middle < right) {
						merge(arr, left, middle, right);
					}
				}

				size *= 2;
			}
		}
};

