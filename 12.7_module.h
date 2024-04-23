#pragma once
#include <string>

using namespace std;

int main_program();
bool isKPeriodic(const string &text, int K);
int KMPSearch(const string& pat, const string& txt);
void computeLPS(string pat, int* lps);
