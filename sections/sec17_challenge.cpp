#include "sec17_challenge.h"
#include <iostream>

using namespace std;

Test::Test()
    : data {0} {
        cout << "\tTest constructor (" << data << ")" << endl;
}

Test::Test(int data)
    : data {data} {
        cout << "\tTest constructor (" << data << ")" << endl;
}

int Test::get_data() const {
    return data;
}

Test::~Test() {
    cout << "\tTest destructor (" << data << ")" << endl;
}

unique_ptr<vector<shared_ptr<Test>>> make() {
    return make_unique<vector<shared_ptr<Test>>> ();
}

void fill(vector<shared_ptr<Test>> &vec, int num) {
    for (int i = 1; i <= num; i++) {
        cout << "Enter data point [" << i << "]: ";
        int data;
        cin >> data;
        vec.push_back(make_shared<Test> (data));
    }
}

void display(const vector<shared_ptr<Test>> &vec) {
    for (auto ptr: vec) {
        cout << ptr->get_data() << endl;
    }
}

void section_17_challenge() {
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    cout << "How many data points do you want to enter?: ";
    int num;
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
}
