//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include "Terminal.h"
#include "gtest/gtest.h"

#define PROG "./Prog"

string roda(const string & dado) {
    string cmd = PROG;
    cmd += ' '+dado;
    Terminal term(cmd);

    auto res1 = term.lePalavra();
    auto res2 = term.lePalavra();
    strip(res1);
    strip(res2);
    if (res1.empty() and res2.empty()) return "";
    if (res1.empty()) return res2;
    if (res2.empty()) return res1;
    return res1+' '+res2;
}

TEST(TermTest, Palindromo) {
    string palavras[] = {"anilina", "arara", "matam", "osso", "radar", "omississimo"};
    for (auto & dado: palavras) {
        string res = roda(dado);
        string rev = dado+' '+dado;

        EXPECT_EQ(rev, res);
    }
}

TEST(TermTest, Normal) {
    string palavras[] = {"banana", "morango", "laranja","sapoti", "siriguela","melancia", "desoxirribonucleico"};
    for (auto & dado: palavras) {
        string res = roda(dado);
        string rev = dado;
        reverse(rev.begin(), rev.end());
        rev += ' '+dado;

        EXPECT_EQ(rev, res);
    }
}

TEST(TermTest, Simples) {
    string palavras[] = {"a","B","c","d","f","G","g","K","z"};
    for (auto & dado: palavras) {
        string res = roda(dado);
        string rev = dado+' '+dado;

        EXPECT_EQ(rev, res);
    }
}

TEST(TermTest, Vazio) {
        string res = roda("");

        EXPECT_EQ("", res);
}
