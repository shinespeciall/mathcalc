#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <Eigen/Dense>

constexpr auto num_e = 2.718281828459045;

void steffensen();
void NewtonMethod();
void NewtonMethod_2Elements();
void Dichotomy();
void ChordMethod();
void MullerMethod();