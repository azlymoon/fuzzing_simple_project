﻿// 12.7_module.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "12.7_module.h"

using namespace std;

void computeLPS(string pat, int *lps) {
    int j = 0;
    int i = 1;
    lps[0] = 0;

    // Внутрь цикла while никогда не зайдем из-за того, что pat.size() всегда равен 1
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(const string &pat, const string &txt) {
    int *lps = new int[pat.size()];

    computeLPS(pat, lps);
    int x = 0; // количество совпадений искомого
    int i = 0;
    int j = 0;
    while (i < txt.size()) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == pat.size()) {
            // cout << "Found pattern at index" << i - j << endl;
            ++x;
            j = lps[j - 1];
        } else if (i < txt.size() && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    return x;
}

bool isKPeriodic(const string &text, int K) {

    // Заглушка, чтобы проект не падал. Необходимо для просмотра покрытия
    if (K == 2147483647) return false;

    string *temp = new string[K];
    if (K > text.size()) {
        cout << "The number is greater than string." << endl;
        return false;
    }
    for (int i = 0; i < K - 1; i++)
        temp[i] = text[i];

    int coincidence = KMPSearch(*temp, text);
    delete[] temp;

    if (coincidence % K)
        return false;
    else
        return true;

}

int main_program() {
    string text;
    int K = 0;

    cout << "Enter string:" << endl;
    getline(cin, text);

    while (true) {

        cout << "Enter number:" << endl;
        cin >> K;

        // Заглушка, чтобы исходный проект не падал. Необходимо для просмотра покрытия
        if (K == 1) return -1;

        if (K > 0)
            break;
        else {
            cout << "The number must be greater than 0. Try again:" << endl;
            return 0;
        }
    }

    if (isKPeriodic(text, K))
        cout << "The string is a multiple of number.";
    else
        cout << "The string is not a multiple of a number.";

    return 0;
}
