#pragma once
#include <string>
#include <vector>
#include <optional>

namespace smanip { 
    /**
     * @brief Counts the number of occurrences of a character in a string.
     * 
     * @param s The string to look for occurrences of the character
     * @param c The character of which to count occurrences of
     * @return std::size_t 
     */
    std::size_t count(const std::string& s, char c);
    std::size_t count(const std::string& s, const std::string& substr);

    std::vector<std::size_t> occurrences(const std::string& s, char c);
    std::vector<std::size_t> occurrences(const std::string& s, const std::string& substr);

    long long hash_str(const std::string& s, const long long modulo = 1e9 + 9);
    std::vector<long long> hash_rolling(const std::string& s, const long long modulo = 1e9 + 9);

    void replace_inplace(
        std::string& s, 
        const std::string& old_str, 
        const std::string& new_str
    );
    std::string replace(
        const std::string& s, 
        const std::string& old_str, 
        const std::string& new_str
    );

    std::vector<std::string> split(const std::string& s, char c);
    std::vector<std::string> split(const std::string& s, const std::string& delimiter);

    std::vector<std::tuple<std::size_t, char>> enumerate(const std::string& s);

    void strip_inplace(std::string& s);
    std::string strip(const std::string& s);
    void lstrip_inplace(std::string& s);
    std::string lstrip(const std::string& s);
    void rstrip_inplace(std::string& s);
    std::string rstrip(const std::string& s);

    bool islower(char c);
    bool islower(const std::string& s);
    bool isupper(char c);
    bool isupper(const std::string& s);
    bool isdigit(char c);
    bool isdigit(const std::string& s);
    bool isalpha(char c);
    bool isalpha(const std::string& s);

    void toupper_inplace(std::string& s);
    std::string toupper(const std::string& s);
    void tolower_inplace(std::string& s);
    std::string tolower(const std::string& s);

    void lpad_inplace(std::string& s, char c, const std::size_t n);
    std::string lpad(const std::string& s, char c, const std::size_t n);
    void rpad_inplace(std::string& s, char c, const std::size_t n);
    std::string rpad(const std::string& s, char c, const std::size_t n);

    std::string slice(
        const std::string& s, 
        const std::optional<int>& start, 
        const std::optional<int>& stop, 
        const std::optional<int>& step);

}

template <typename T>
std::string vtos(const std::vector<T>& v, char delimiter);

template <typename T>
std::string vtos(const std::vector<T>& v, const std::string& delimiter);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v);

template <typename T>
std::istream& operator>(std::istream& in, std::vector<T>& v);

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& v);

template <typename T>
std::istream& vector_read(std::istream& in, std::vector<T>& v, std::size_t n);