#include <iostream>
#include <thread>

int main()
{
repeat:
    std::cout << "credit\n";

    std::this_thread::sleep_for(std::chrono::seconds(3));// 3 秒待つ

    std::cout << "title\n";

    std::this_thread::sleep_for(std::chrono::seconds(3));// 3 秒待つ

    std::cout << "opening\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));// 5 秒待つ

    std::cout << "demo\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));// 5 秒待つ
    
    goto repeat;
}

