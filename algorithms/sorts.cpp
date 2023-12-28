#include <vector>
#include <iostream>

void bubble_sort(std::vector<int> &vector) {
    size_t vector_length = vector.size();
    for (int i = 0; i < vector_length; ++i) {
        for (int j = i + 1; j < vector_length; ++j) {
            if (vector[i] > vector[j]) {
                std::swap(vector[i], vector[j]);
            }
        }
    }
}

std::vector<int> merge_two_sorted_vectors(std::vector<int> &vec1, std::vector<int> &vec2) {
    int iter1 = 0;
    int iter2 = 0;
    size_t len1 = vec1.size();
    size_t len2 = vec2.size();
    std::vector<int> result_vector;

    while (iter1 < len1 || iter2 < len2) {
        if (iter1 == len1 || iter2 < len2 && vec1[iter1] > vec2[iter2]) {
            result_vector.push_back(vec2[iter2++]);
        } else {
            result_vector.push_back(vec1[iter1++]);
        }
    }

    return result_vector;
}

std::vector<int> vector_slice(std::vector<int> &vector, int left, int right) {
    std::vector<int> result;

    for (size_t i = left; i < right; ++i) {
        result.push_back(vector[i]);
    }
    return result;
}

std::vector<int> merge_sort(std::vector<int> &vector) {
    size_t len = vector.size();

    if (len <= 1)
        return vector;

    std::vector<int> left_vector = vector_slice(vector, 0, len / 2);
    std::vector<int> right_vector = vector_slice(vector, len / 2, len);
    left_vector = merge_sort(left_vector);
    right_vector = merge_sort(right_vector);

    return merge_two_sorted_vectors(left_vector, right_vector);
}

int main() {
    std::vector<int> x = {10, 2, 5, 11, 111, 3};
    std::vector<int> x1 = {1, 3, 5, 6};
    std::vector<int> x2 = {2, 4, 7};
    std::vector<int> result = merge_two_sorted_vectors(x1, x2);
    for (auto element: result) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    result = vector_slice(result, 1, 4);
    for (auto element: result) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    x = merge_sort(x);
    for (auto element: x) {
        std::cout << element << ' ';
    }
}