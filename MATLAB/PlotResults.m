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

LL_out_1 = readtable('../bin/LL_out_1.csv');
LL_out_1 = table2array(LL_out_1);

LL_out_2 = readtable('../bin/LL_out_2.csv');
LL_out_2 = table2array(LL_out_2);

LinHash_out_1 = readtable('../bin/LinHash_out_1.csv');
LinHash_out_1 = table2array(LinHash_out_1);
LinHash_Collision_1 = LinHash_out_1(:,3);
LinHash_Search_1 = LinHash_out_1(:,4);
LinHash_out_1 = LinHash_out_1(:,[1 2]);

LinHash_out_2 = readtable('../bin/LinHash_out_2.csv');
LinHash_out_2 = table2array(LinHash_out_2);
LinHash_Collision_2 = LinHash_out_2(:,3);
LinHash_Search_2 = LinHash_out_2(:,4);
LinHash_out_2 = LinHash_out_2(:,[1 2]);

LLHash_out_1 = readtable('../bin/LLHash_out_1.csv');
LLHash_out_1 = table2array(LLHash_out_1);
LLHash_Collision_1 = LLHash_out_1(:,3);
LLHash_Search_1 = LLHash_out_1(:,4);
LLHash_out_1 = LLHash_out_1(:,[1 2]);

LLHash_out_2 = readtable('../bin/LLHash_out_2.csv');
LLHash_out_2 = table2array(LLHash_out_2);
LLHash_Collision_2 = LLHash_out_2(:,3);
LLHash_Search_2 = LLHash_out_2(:,4);
LLHash_out_2 = LLHash_out_2(:,[1 2]);

QuadHash_out_1 = readtable('../bin/QuadHash_out_1.csv');
QuadHash_out_1 = table2array(QuadHash_out_1);
QuadHash_Collision_1 = QuadHash_out_1(:,3);
QuadHash_Search_1 = QuadHash_out_1(:,4);
QuadHash_out_1 = QuadHash_out_1(:,[1 2]);

QuadHash_out_2 = readtable('../bin/QuadHash_out_2.csv');
QuadHash_out_2 = table2array(QuadHash_out_2);
QuadHash_Collision_2 = QuadHash_out_2(:,3);
QuadHash_Search_2 = QuadHash_out_2(:,4);
QuadHash_out_2 = QuadHash_out_2(:,[1 2]);

%% PLOT BST
f1 = figure;
figure(f1);
plot(BST_out_1, 'LineWidth',1.5);
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f1, '-depsc', 'BST_out_A');

f2 = figure;
figure(f2);
plot(BST_out_2, 'LineWidth',1.5);
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f2, '-depsc', 'BST_out_B');

%% PLOT Linked List
f5 = figure;
figure(f5);
plot(LL_out_1, 'LineWidth',1.5);
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f5, '-depsc', 'LL_out_A');

f6 = figure;
figure(f6);
plot(LL_out_2, 'LineWidth',1.5);
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f6, '-depsc', 'LL_out_B');

%% PLOT Linear Probing Hash table
f3 = figure;
figure(f3);
yyaxis left
hold on
plot(LinHash_out_1(:,1), 'LineWidth',1.5);
plot(LinHash_out_1(:,2), 'r-', 'LineWidth',1.5);

yyaxis right
plot(LinHash_Collision_1, 'k*', 'LineWidth', 1.0);
plot(LinHash_Search_1, 'm.');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Insert Collisions', 'Search Collisions', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f3, '-depsc', 'LinHash_out_A');

f4 = figure;
figure(f4);
yyaxis left
hold on
plot(LinHash_out_2(:,1), 'LineWidth',1.5);
plot(LinHash_out_2(:,2), 'r-', 'LineWidth',1.5);

yyaxis right
plot(LinHash_Collision_2, 'k*', 'LineWidth', 1.0);
plot(LinHash_Search_2, 'm.');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Insert Collisions', 'Search Collisions', 'Location', 'northwest');


% Output the plot to EPS for LATEX
print(f4, '-depsc', 'LinHash_out_B');

%% PLOT Chaining Hash Table
f7 = figure;
figure(f7);
yyaxis left
hold on
plot(LLHash_out_1(:,1), 'LineWidth',1.5);
plot(LLHash_out_1(:,2), 'r-', 'LineWidth',1.5);

yyaxis right
plot(LLHash_Collision_1, 'k*', 'LineWidth', 1.0);
plot(LLHash_Search_1, 'm.');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Insert Collisions', 'Search Collisions', 'Location', 'northwest');


% Output the plot to EPS for LATEX
print(f7, '-depsc', 'LLHash_out_A');

f8 = figure;
figure(f8);
yyaxis left
hold on
plot(LLHash_out_2(:,1), 'LineWidth',1.5);
plot(LLHash_out_2(:,2), 'r-', 'LineWidth',1.5);

yyaxis right
plot(LLHash_Collision_2, 'k*', 'LineWidth', 1.0);
plot(LLHash_Search_2, 'm.');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Insert Collisions', 'Search Collisions', 'Location', 'northwest');


% Output the plot to EPS for LATEX
print(f8, '-depsc', 'LLHash_out_B');

%% PLOT Quadratic Probing Hash Table
f9 = figure;
figure(f9);
yyaxis left
hold on
plot(QuadHash_out_1(:,1), 'LineWidth',1.5);
plot(QuadHash_out_1(:,2), 'r-', 'LineWidth',1.5);

yyaxis right
plot(QuadHash_Collision_1, 'k*', 'LineWidth', 1.0);
plot(QuadHash_Search_1, 'm.');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Insert Collisions', 'Search Collisions', 'Location', 'northwest');


% Output the plot to EPS for LATEX
print(f9, '-depsc', 'QuadHash_out_A');

f10 = figure;
figure(f10);
yyaxis left
hold on
plot(QuadHash_out_2(:,1), 'LineWidth',1.5);
plot(QuadHash_out_2(:,2), 'r-', 'LineWidth',1.5);

yyaxis right
plot(QuadHash_Collision_2, 'k*', 'LineWidth', 1.0);
plot(QuadHash_Search_2, 'm.');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Insert Collisions', 'Search Collisions', 'Location', 'northwest');


% Output the plot to EPS for LATEX
print(f10, '-depsc', 'QuadHash_out_B');
