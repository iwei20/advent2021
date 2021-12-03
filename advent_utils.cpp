#include "advent_utils.hpp"
#include <cstdarg>
#include <iostream>
#include <vector>
#include <sstream>

constexpr long long ALPHABET_SIZE = 257;
constexpr long long HASH_MOD = (long long)1e9 + 9;
std::size_t smanip::count(const std::string& s, char c) {
    std::size_t result = 0;
    for (char ch : s) {
        if (c == ch) ++result;
    }
    return result;
}

std::size_t smanip::count(const std::string& s, const std::string& substr) {
    std::size_t result = 0;
    if(substr.size() > s.size()) return result;
    if(s.size() == 0 || substr.size() == 0) return result;

    long long match_pattern = hash_str(substr, HASH_MOD);
    std::vector<long long> patterns = hash_rolling(s, HASH_MOD);

    for (std::size_t i = 0; i < s.size() - substr.size() + 1; ++i) {
        long long curr_pattern = (patterns[i + substr.size() - 1] - (i > 0 ? patterns[i - 1] : 0) + HASH_MOD) % HASH_MOD;
        if (curr_pattern == match_pattern) ++result;
        match_pattern *= ALPHABET_SIZE;
        match_pattern %= HASH_MOD;
    }
    return result;
}

std::vector<std::size_t> smanip::occurrences(const std::string& s, char c) {
    std::vector<std::size_t> result;
    for (std::size_t i = 0; i < s.size(); ++i) {
        if (c == s[i]) result.push_back(i);
    }
    return result;
}

std::vector<std::size_t> smanip::occurrences(const std::string& s, const std::string& substr) {
    std::vector<std::size_t> result;
    if(substr.size() > s.size()) return result;
    if(s.size() == 0 || substr.size() == 0) return result;

    long long match_pattern = hash_str(substr, HASH_MOD);
    std::vector<long long> patterns = hash_rolling(s, HASH_MOD);

    for (std::size_t i = 0; i < s.size() - substr.size() + 1; ++i) {
        long long curr_pattern = (patterns[i + substr.size() - 1] - (i > 0 ? patterns[i - 1] : 0) + HASH_MOD) % HASH_MOD;
        if (curr_pattern == match_pattern) result.push_back(i);
        match_pattern *= ALPHABET_SIZE;
        match_pattern %= HASH_MOD;
    }
    return result;
}

long long smanip::hash_str(const std::string& s, const long long modulo) {
    long long result = 0;
    long long pow = 1;
    for (char c : s) {
        result += pow * (long long)c;
        result %= modulo;
        pow *= ALPHABET_SIZE;
        pow %= modulo;
    }
    return result;
}

std::vector<long long> smanip::hash_rolling(const std::string& s, const long long modulo) {
    std::vector<long long> result(s.size());
    long long pow = ALPHABET_SIZE;
    result[0] = s[0] % modulo;
    for (std::size_t i = 1; i < s.size(); ++i) {
        result[i] = result[i - 1] + pow * (long long)s[i];
        result[i] %= modulo;
        pow *= ALPHABET_SIZE;
        pow %= modulo;
    }
    return result;
}

std::string smanip::slice(
        const std::string& s, 
        const std::optional<int>& start, 
        const std::optional<int>& stop, 
        const std::optional<int>& step) {

    // Implementation taken from CPython
    int length = (int) s.size();
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
    for (std::size_t pos = m_start, i = 0; i < (std::size_t) slicelength; pos += m_step, ++i) {
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
template std::string vtos<>(const std::vector<std::size_t>& v, char delimiter);
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
template std::string vtos<>(const std::vector<std::size_t>& v, const std::string& delimiter);
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
template std::ostream& operator<<<>(std::ostream& out, const std::vector<std::size_t>& v);
template std::ostream& operator<<<>(std::ostream& out, const std::vector<std::string>& v);

template <typename T>
std::istream& operator>(std::istream& in, std::vector<T>& v) {
    T t;
    in >> t;
    v.push_back(t);
    return in;
}

template std::istream& operator><>(std::istream& in, std::vector<int>& v);
template std::istream& operator><>(std::istream& in, std::vector<char>& v);
template std::istream& operator><>(std::istream& in, std::vector<double>& v);
template std::istream& operator><>(std::istream& in, std::vector<long long>& v);
template std::istream& operator><>(std::istream& in, std::vector<std::size_t>& v);
template std::istream& operator><>(std::istream& in, std::vector<std::string>& v); 

template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& v) {
    T t;
    while(in >> t) {
        v.push_back(t);
    }
    return in;
}

template std::istream& operator>><>(std::istream& in, std::vector<int>& v);
template std::istream& operator>><>(std::istream& in, std::vector<char>& v);
template std::istream& operator>><>(std::istream& in, std::vector<double>& v);
template std::istream& operator>><>(std::istream& in, std::vector<long long>& v);
template std::istream& operator>><>(std::istream& in, std::vector<std::size_t>& v);
template std::istream& operator>><>(std::istream& in, std::vector<std::string>& v); 

template <typename T>
std::istream& vector_read(std::istream& in, std::vector<T>& v, std::size_t n) {
    T t;
    for (std::size_t i = 0; i < n; ++i) {
        in >> t;
        v.push_back(t);
    }
    return in;
}

template std::istream& vector_read<>(std::istream& in, std::vector<int>& v, std::size_t n);
template std::istream& vector_read<>(std::istream& in, std::vector<char>& v, std::size_t n);
template std::istream& vector_read<>(std::istream& in, std::vector<double>& v, std::size_t n);
template std::istream& vector_read<>(std::istream& in, std::vector<long long>& v, std::size_t n);
template std::istream& vector_read<>(std::istream& in, std::vector<std::size_t>& v, std::size_t n);
template std::istream& vector_read<>(std::istream& in, std::vector<std::string>& v, std::size_t n);