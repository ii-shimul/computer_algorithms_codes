#include <bits/stdc++.h>
using namespace std;

struct Student {
  int id;
  float mark;
};

bool compareMark(Student s1, Student s2) {
  if (s1.mark < s2.mark) return true;
  else return false;
}

int main() {
  int n; cin >> n;
  Student info[n];
  for (int i = 0; i < n; i++) {
    cin >> info[i].id >> info[i].mark;
  }

  sort(info, info + n, compareMark);

  for (int i = 0; i < n; i++) {
    cout << info[i].id << " " << info[i].mark << " " << endl;
  }


}