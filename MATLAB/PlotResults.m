%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                         %
%        CSCI 2270 - Data Structures and Algorithms       %
%               Final Project MATLAB Script               %
%                                                         %
%                                                         %
%                     Jason Popich                        %
%                 Matthew Januszewski                     %
%                                                         %
%                      04/24/2020                         %
%                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Setup Env
clear
clc

%% LOAD DATA
BST_out_1 = readtable('../bin/BST_out_1.csv');
BST_out_1 = table2array(BST_out_1);

BST_out_2 = readtable('../bin/BST_out_2.csv');
BST_out_2 = table2array(BST_out_2);

LinHash_out_1 = readtable('../bin/LinHash_out_1.csv');
LinHash_out_1 = table2array(LinHash_out_1);

LinHash_out_2 = readtable('../bin/LinHash_out_2.csv');
LinHash_out_2 = table2array(LinHash_out_2);

LL_out_1 = readtable('../bin/LL_out_1.csv');
LL_out_1 = table2array(LL_out_1);

LL_out_2 = readtable('../bin/LL_out_2.csv');
LL_out_2 = table2array(LL_out_2);

LLHash_out_1 = readtable('../bin/LLHash_out_1.csv');
LLHash_out_1 = table2array(LLHash_out_1);

LLHash_out_2 = readtable('../bin/LLHash_out_2.csv');
LLHash_out_2 = table2array(LLHash_out_2);

QuadHash_out_1 = readtable('../bin/QuadHash_out_1.csv');
QuadHash_out_1 = table2array(QuadHash_out_1);

QuadHash_out_2 = readtable('../bin/QuadHash_out_2.csv');
QuadHash_out_2 = table2array(QuadHash_out_2);

%% PLOT BST
f1 = figure;
figure(f1);
plot(BST_out_1, 'LineWidth',1.5);

% Output the plot to EPS for LATEX
print(f1, '-deps', 'BST_out_A');

f2 = figure;
figure(f2);
plot(BST_out_2, 'LineWidth',1.5);

% Output the plot to EPS for LATEX
print(f2, '-deps', 'BST_out_B');

%% PLOT Linear Probing Hash table
f3 = figure;
figure(f3);
plot(LinHash_out_1, 'LineWidth',1.5);

% Output the plot to EPS for LATEX
print(f3, '-deps', 'LinHash_out_A');

f4 = figure;
figure(f4);
plot(LinHash_out_2, 'LineWidth',1.5);

% Output the plot to EPS for LATEX
print(f4, '-deps', 'LinHash_out_B');

%% PLOT Linked List
f5 = figure;
figure(f5);
plot(LL_out_1, 'LineWidth',1.5);

% Output the plot to EPS for LATEX
print(f5, '-deps', 'LL_out_A');

f6 = figure;
figure(f6);
plot(LL_out_2, 'LineWidth',1.5);

% Output the plot to EPS for LATEX
print(f6, '-deps', 'LL_out_B');

%% PLOT Chaining Hash Table
f7 = figure;
figure(f7);
plot(LLHash_out_1, 'LineWidth',1.5);

% Output the plot to EPS for LATEX
print(f7, '-deps', 'LLHash_out_A');

f8 = figure;
figure(f8);
plot(LLHash_out_2, 'LineWidth',1.5);

% Output the plot to EPS for LATEX
print(f8, '-deps', 'LLHash_out_B');

%% PLOT Quadratic Probing Hash Table
f9 = figure;
figure(f9);
plot(QuadHash_out_1, 'LineWidth',1.5);

% Output the plot to EPS for LATEX
print(f9, '-deps', 'QuadHash_out_A');

f10 = figure;
figure(f10);
plot(QuadHash_out_2, 'LineWidth',1.5);

% Output the plot to EPS for LATEX
print(f10, '-deps', 'QuadHash_out_B');
