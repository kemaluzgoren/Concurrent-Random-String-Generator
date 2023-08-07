#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <random>

// Function to generate a random string of letters of length n
std::string generateRandomLetters(int n) {
    using namespace std::literals;

    std::string s(n, '\0');

    // Random number generation for characters 'A' to 'Z'
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis('A', 'Z');

    // Generate the string by randomly picking characters and filling the string
    std::generate_n(s.begin(), n, [&]() { return dis(gen); });

    // Simulate some processing time (3 seconds) for demonstration purposes
    std::this_thread::sleep_for(1s);

    return s;
}

// Function to generate a random string of digits of length n
std::string generateRandomDigits(int n) {
    using namespace std::literals;

    std::string s(n, '\0');

    // Random number generation for digits '0' to '9'
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis('0', '9');

    // Generate the string by randomly picking digits and filling the string
    std::generate_n(s.begin(), n, [&]() { return dis(gen); });

    // Simulate some processing time (3 seconds) for demonstration purposes
    std::this_thread::sleep_for(1s);

    return s;
}

int main() {

    int num_letters, num_digits;

    // Get the number of letters from the user
    std::cout << "Enter the number of letters: ";
    std::cin >> num_letters;

    // Get the number of digits from the user
    std::cout << "Enter the number of digits: ";
    std::cin >> num_digits;
    
    // Start the timer
    auto start = std::chrono::steady_clock::now();

    std::string s1, s2;

    // Create two threads to generate strings concurrently
    std::thread thread1([&]() { s1 = generateRandomLetters(num_letters); });
    std::thread thread2([&]() { s2 = generateRandomDigits(num_digits); });

    // Wait for both threads to finish their work
    thread1.join();
    thread2.join();

    // Stop the timer and calculate the duration
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double>(end - start).count() << " saniye\n";

    // Concatenate the generated strings and print the result
    std::cout << s1 + s2 << "\n";
}