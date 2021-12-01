#include "advent_utils.hpp"
#include <cstdarg>
#include <iostream>
#include <vector>
#include <sstream>

constexpr long long ALPHABET_SIZE = 256;

std::size_t smanip::count(const std::string& s, char c) {
    std::size_t result = 0;
    for (char ch : s) {
        if (c == ch) ++result;
    }
    return result;
}

std::size_t smanip::count(const std::string& s, const std::string& substr) {
    std::vector<long long> hashes = hash_rolling(s);
    long long curr_match = hash_str(substr);
    std::size_t substr_length = substr.size();
    std::size_t result = 0;
    for (std::size_t i = 0; i < s.size() - substr_length + 1; ++i) {
        std::cout << curr_match << " " << hashes[i + substr_length - 1] << " " << (i > 0 ? hashes[i - 1] : 0) << "\n";
        if (curr_match == (hashes[i + substr_length - 1] - (i > 0 ? hashes[i - 1] : 0) + (long long)(1e9 + 9)) % (long long)(1e9 + 9)) ++result;
        curr_match *= ALPHABET_SIZE;
        curr_match %= (long long)(1e9 + 9);
    }
    return result;
}

long long smanip::hash_str(const std::string& s, const long long modulo) {
    long long result = 0;
    for (char c : s) {
        result *= ALPHABET_SIZE;
        result %= modulo;
        result += (long long)c;
    }
    return result;
}

std::vector<long long> smanip::hash_rolling(const std::string& s, const long long modulo) {
    std::vector<long long> result(s.size());
    result[0] = s[0] % modulo;
    for (std::size_t i = 1; i < s.size(); ++i) {
        result[i] = result[i - 1] * ALPHABET_SIZE;
        result[i] %= modulo;
        result[i] += (long long)s[i];
    }
    return result;
}

std::string smanip::slice(
        const std::string& s, 
        const std::optional<int>& start, 
        const std::optional<int>& stop, 
        const std::optional<int>& step) {

    // Implementation taken from CPython
    int length = s.size();
    int m_start, m_stop; 

    int m_step = step.value_or(1);
    if (m_step == 0) std::cerr << "Step cannot be 0\n";
    
    if (!start.has_value()) {
        m_start = m_step > 0 ? 0 : length - 1;
    } else {
        m_start = start.value();
        if (m_start < 0) m_start += length;
        if (m_start < 0) m_start = (m_step < 0) ? -1 : 0;
        if (m_start >= length) m_start = (m_step < 0) ? length - 1: length;
    }

    if (!stop.has_value()) {
        m_stop = m_step > 0 ? length : -1;
    } else {
        m_stop = stop.value();
        if (m_stop < 0) m_stop += length;
        if (m_stop < 0) m_stop = (m_step < 0) ? -1 : 0;
        if (m_stop >= length) m_stop = (m_stop < 0) ? length - 1: length;
    }

    int slicelength;
    if ((m_step < 0 && m_stop >= m_start) || 
        (m_step > 0 && m_stop <= m_start)) {
        slicelength = 0;
    } else if (m_step < 0) {
        slicelength = (m_stop - m_start + 1) / (m_step) + 1;
    } else {
        slicelength = (m_stop - m_start - 1) / (m_step) + 1;
    }

    if (slicelength <= 0) {
        return "";
    }
    
    if (m_step == 1) {
        return s.substr(m_start, m_stop - m_start);
    } 

    std::string result;
    result.resize(slicelength);
    for (std::size_t pos = m_start, i = 0; i < slicelength; pos += m_step, ++i) {
        result[i] = s[pos];
    }
    return result;
}

template <typename T>
std::string vtos(const std::vector<T>& v, char delimiter) {
    std::stringstream ss;
    for (std::size_t i = 0; i < v.size(); ++i) {
        ss << v[i];
        if (i < v.size() - 1) {
            ss << delimiter;
        }
    }
    return ss.str();
}

template std::string vtos<>(const std::vector<int>& v, char delimiter);
template std::string vtos<>(const std::vector<char>& v, char delimiter);
template std::string vtos<>(const std::vector<double>& v, char delimiter);
template std::string vtos<>(const std::vector<long long>& v, char delimiter);
template std::string vtos<>(const std::vector<std::string>& v, char delimiter);

template <typename T>
std::string vtos(const std::vector<T>& v, const std::string& delimiter) {
    std::stringstream ss;
    for (std::size_t i = 0; i < v.size(); ++i) {
        ss << v[i];
        if (i < v.size() - 1) {
            ss << delimiter;
        }
    }
    return ss.str();
}

template std::string vtos<>(const std::vector<int>& v, const std::string& delimiter);
template std::string vtos<>(const std::vector<char>& v, const std::string& delimiter);
template std::string vtos<>(const std::vector<double>& v, const std::string& delimiter);
template std::string vtos<>(const std::vector<long long>& v, const std::string& delimiter);
template std::string vtos<>(const std::vector<std::string>& v, const std::string& delimiter);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    out << vtos(v, ' ');
    return out;
}

template std::ostream& operator<<<>(std::ostream& out, const std::vector<int>& v);
template std::ostream& operator<<<>(std::ostream& out, const std::vector<char>& v);
template std::ostream& operator<<<>(std::ostream& out, const std::vector<double>& v);
template std::ostream& operator<<<>(std::ostream& out, const std::vector<long long>& v);
template std::ostream& operator<<<>(std::ostream& out, const std::vector<std::string>& v);