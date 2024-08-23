#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calculateTotalMarks(vector<int> marks)
{
    return marks[0] + marks[1] + marks[2];
}

bool compare(pair<string, vector<int>> s1, pair<string, vector<int>> s2)
{
    vector<int> marks1 = s1.second;
    vector<int> marks2 = s2.second;

    return calculateTotalMarks(marks1) > calculateTotalMarks(marks2);
}

int main()
{
    // vector of pair of string and vector of int
    vector<pair<string, vector<int>>> student_marks = {{"Rohan",
                                                        {10, 20, 11}},
                                                       {"Prateek",
                                                        {10, 21, 3}},
                                                       {"Vivek",
                                                        {4, 5, 6}},
                                                       {"Rahul",
                                                        {10, 13, 20}}};

    sort(student_marks.begin(), student_marks.end(), compare);

    for (pair<string, vector<int>> s : student_marks)
        cout << s.first << " " << calculateTotalMarks(s.second) << endl;

    return 0;
}