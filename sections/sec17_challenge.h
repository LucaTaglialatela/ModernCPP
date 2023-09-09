#ifndef _SEC17_CHALLENGE_H_
#define _SEC17_CHALLENGE_H_

#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test();
    Test(int data);
    int get_data() const;
    ~Test();
};

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

void section_17_challenge();

#endif