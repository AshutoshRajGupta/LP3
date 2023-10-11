#include <iostream>
#include <vector>
#include <chrono>
#include <future>
#include <random>
#include <algorithm>
#include <thread>

using namespace std;

// Function to merge two sorted vectors
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> merged;
    size_t left_index = 0, right_index = 0;

    while (left_index < left.size() && right_index < right.size()) {
        if (left[left_index] <= right[right_index]) {
            merged.push_back(left[left_index]);
            left_index++;
        } else {
            merged.push_back(right[right_index]);
            right_index++;
        }
    }

    while (left_index < left.size()) {
        merged.push_back(left[left_index]);
        left_index++;
    }

    while (right_index < right.size()) {
        merged.push_back(right[right_index]);
        right_index++;
    }

    return merged;
}

// Standard merge sort algorithm
vector<int> merge_sort(const vector<int>& data) {
    size_t length = data.size();
    if (length <= 1) {
        return data;
    }

    size_t middle = length / 2;
    vector<int> left(data.begin(), data.begin() + middle);
    vector<int> right(data.begin() + middle, data.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}

// Multithreaded merge sort
vector<int> merge_sort_multithreaded(const vector<int>& data, int threads) {
    size_t length = data.size();
    if (length <= 1) {
        return data;
    }

    size_t middle = length / 2;
    vector<int> left(data.begin(), data.begin() + middle);
    vector<int> right(data.begin() + middle, data.end());

    if (threads > 1) {
        future<vector<int>> left_future = async(launch::async, merge_sort_multithreaded, ref(left), threads / 2);
        vector<int> right_result = merge_sort_multithreaded(right, threads - threads / 2);
        left = left_future.get();

        return merge(left, right_result);
    } else {
        left = merge_sort(left);
        right = merge_sort(right);
        return merge(left, right);
    }
}

// Generate a random vector with n elements
vector<int> generate_random_vector(int n) {
    vector<int> data;
    data.reserve(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, n * 2);

    for (int i = 0; i < n; i++) {
        data.push_back(dis(gen));
    }

    return data;
}

int main() {
    int size = 10000;  // Adjust the size as needed
    int num_threads = thread::hardware_concurrency();

    // Generate a random unsorted array
    vector<int> data_unsorted = generate_random_vector(size);

    // Test merge_sort
    auto start_time = chrono::high_resolution_clock::now();
    vector<int> data_sorted = merge_sort(data_unsorted);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cout << "Time taken for merge_sort: " << duration.count() << " milliseconds" << endl;

    // Test merge_sort_multithreaded
    start_time = chrono::high_resolution_clock::now();
    data_sorted = merge_sort_multithreaded(data_unsorted, num_threads);
    end_time = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cout << "Time taken for merge_sort_multithreaded: " << duration.count() << " milliseconds" << endl;

    return 0;
}
