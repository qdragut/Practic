#include <iostream>

using namespace std;

bool canAllStudentsSit(int M, int N, int X) {
    int totalSeats = M * N;
    return X <= totalSeats;
}

int countStudentsNotOnFavoriteRow(int M, int N, int X) {
    if (!canAllStudentsSit(M, N, X)) {
        return X - M * N;
    }

    int studentsNotOnFavorite = 0;
    int remainingSeats = M * N;
    int studentsLeft = X;
    for (int row = 1; row <= M && studentsLeft > 0; ++row) {
        int seatsInRow = N;
        if (studentsLeft <= seatsInRow) {
            break;
        }
        else {
            studentsNotOnFavorite += studentsLeft - seatsInRow;
            studentsLeft -= seatsInRow;
        }
    }
    return studentsNotOnFavorite;
}

int binarySearch(int M, int N, int maxStudents) {
    int left = 0;
    int right = maxStudents;
    int result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (countStudentsNotOnFavoriteRow(M, N, mid) > 0) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RU");
    int M, N, X;
    cout << "Введите количество рядов M: ";
    cin >> M;
    cout << "Введите количество мест в ряду N: ";
    cin >> N;
    cout << "Введите количество студентов X: ";
    cin >> X;

    if (!canAllStudentsSit(M, N, X)) {
        cout << "Не все студенты смогут сесть(((( Количество студентов, не севших на любимый ряд: "
            << X - M * N << endl;
    }
    else {
        int studentsNotOnFavorite = countStudentsNotOnFavoriteRow(M, N, X);
        cout << "Количество студентов, не севших на любимый ряд: "
            << studentsNotOnFavorite << endl;
    }

    int maxStudents = M * N * 2; 
    int minStudentsNotSitting = binarySearch(M, N, maxStudents);
    cout << "Минимальное количество студентов, при котором хотя бы один не сядет на любимый ряд: "
        << minStudentsNotSitting << endl;
}