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
BST_out_1=rmoutliers(BST_out_1);

BST_out_2 = readtable('../bin/BST_out_2.csv');
BST_out_2 = table2array(BST_out_2);
BST_out_2=rmoutliers(BST_out_2);

LL_out_1 = readtable('../bin/LL_out_1.csv');
LL_out_1 = table2array(LL_out_1);
LL_out_1=rmoutliers(LL_out_1);

LL_out_2 = readtable('../bin/LL_out_2.csv');
LL_out_2 = table2array(LL_out_2);
LL_out_2=rmoutliers(LL_out_2);

LinHash_out_1 = readtable('../bin/LinHash_out_1.csv');
LinHash_out_1 = table2array(LinHash_out_1);
LinHash_out_1=rmoutliers(LinHash_out_1);
LinHash_Collision_1 = LinHash_out_1(:,3);
LinHash_Search_1 = LinHash_out_1(:,4);
LinHash_out_1 = LinHash_out_1(:,[1 2]);

LinHash_out_2 = readtable('../bin/LinHash_out_2.csv');
LinHash_out_2 = table2array(LinHash_out_2);
LinHash_out_2=rmoutliers(LinHash_out_2);
LinHash_Collision_2 = LinHash_out_2(:,3);
LinHash_Search_2 = LinHash_out_2(:,4);
LinHash_out_2 = LinHash_out_2(:,[1 2]);

LLHash_out_1 = readtable('../bin/LLHash_out_1.csv');
LLHash_out_1 = table2array(LLHash_out_1);
LLHash_out_1=rmoutliers(LLHash_out_1);
LLHash_Collision_1 = LLHash_out_1(:,3);
LLHash_Search_1 = LLHash_out_1(:,4);
LLHash_out_1 = LLHash_out_1(:,[1 2]);

LLHash_out_2 = readtable('../bin/LLHash_out_2.csv');
LLHash_out_2 = table2array(LLHash_out_2);
LLHash_out_2=rmoutliers(LLHash_out_2);
LLHash_Collision_2 = LLHash_out_2(:,3);
LLHash_Search_2 = LLHash_out_2(:,4);
LLHash_out_2 = LLHash_out_2(:,[1 2]);

QuadHash_out_1 = readtable('../bin/QuadHash_out_1.csv');
QuadHash_out_1 = table2array(QuadHash_out_1);
QuadHash_out_1=rmoutliers(QuadHash_out_1);
QuadHash_Collision_1 = QuadHash_out_1(:,3);
QuadHash_Search_1 = QuadHash_out_1(:,4);
QuadHash_out_1 = QuadHash_out_1(:,[1 2]);

QuadHash_out_2 = readtable('../bin/QuadHash_out_2.csv');
QuadHash_out_2 = table2array(QuadHash_out_2);
QuadHash_out_2=rmoutliers(QuadHash_out_2);
QuadHash_Collision_2 = QuadHash_out_2(:,3);
QuadHash_Search_2 = QuadHash_out_2(:,4);
QuadHash_out_2 = QuadHash_out_2(:,[1 2]);

%% PLOT BST
f1 = figure;
figure(f1);
plot(BST_out_1, 'LineWidth',1.5);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f1, '-depsc', 'BST_out_A');

f2 = figure;
figure(f2);
plot(BST_out_2, 'LineWidth',1.5);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f2, '-depsc', 'BST_out_B');

%% PLOT Linked List
f3 = figure;
figure(f3);
plot(LL_out_1, 'LineWidth',1.5);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f3, '-depsc', 'LL_out_A');

f4 = figure;
figure(f4);
plot(LL_out_2, 'LineWidth',1.5);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f4, '-depsc', 'LL_out_B');

%% PLOT Linear Probing Hash table
f5 = figure;
figure(f5);
hold on
plot(LinHash_out_1(:,1), 'LineWidth', 1.5);
plot(LinHash_out_1(:,2), 'LineWidth', 1.5);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f5, '-depsc', 'LinHash_INS_out_A');


f6 = figure;
figure(f6);
hold on
plot(LinHash_Collision_1, 'LineWidth', 1.5);
plot(LinHash_Search_1, 'LineWidth', 1.5);
ylabel('Collisions');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Collisions', 'Search Collisions', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f6, '-depsc', 'LinHash_COLL_out_A');

f7 = figure;
figure(f7);
hold on
plot(LinHash_out_2(:,1), 'LineWidth',1.5);
plot(LinHash_out_2(:,2), 'LineWidth', 1.5);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f7, '-depsc', 'LinHash_INS_out_B');

f8 = figure;
figure(f8);
hold on
plot(LinHash_Collision_2, 'LineWidth', 1.5);
plot(LinHash_Search_2, 'LineWidth', 1.5);
ylabel('Collisions');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Collisions', 'Search Collisions', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f8, '-depsc', 'LinHash_COLL_out_B');

%% PLOT Chaining Hash Table
f9 = figure;
figure(f9);
hold on
plot(LLHash_out_1(:,1), 'LineWidth', 1.5);
plot(LLHash_out_1(:,2), 'LineWidth', 1.5);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f9, '-depsc', 'LLHash_INS_out_A');

f10 = figure;
figure(f10);
hold on
plot(LLHash_Collision_1, 'LineWidth', 1.5);
plot(LLHash_Search_1, 'LineWidth', 1.5);
ylabel('Collisions');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Collisions', 'Search Collisions', 'Location', 'northwest');


% Output the plot to EPS for LATEX
print(f10, '-depsc', 'LLHash_COLL_out_A');

f11 = figure;
figure(f11);
hold on
plot(LLHash_out_2(:,1), 'LineWidth',1.5);
plot(LLHash_out_2(:,2), 'LineWidth', 1.5);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f11, '-depsc', 'LLHash_INS_out_B');

f12 = figure;
figure(f12);
hold on
plot(LLHash_Collision_2, 'LineWidth', 1.5);
plot(LLHash_Search_2, 'LineWidth', 1.5);
ylabel('Collisions');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Collisions', 'Search Collisions', 'Location', 'northwest');


% Output the plot to EPS for LATEX
print(f12, '-depsc', 'LLHash_COLL_out_B');

%% PLOT Quadratic Probing Hash Table
f13 = figure;
figure(f13);
hold on
plot(QuadHash_out_1(:,1), 'LineWidth', 1.5);
plot(QuadHash_out_1(:,2), 'LineWidth', 1.5);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f13, '-depsc', 'QuadHash_INS_out_A');

f14 = figure;
figure(f14);
hold on
plot(QuadHash_Collision_1, 'LineWidth', 1.5);
plot(QuadHash_Search_1, 'LineWidth', 1.5);
ylabel('Collisions');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Collisions', 'Search Collisions', 'Location', 'northwest');


% Output the plot to EPS for LATEX
print(f14, '-depsc', 'QuadHash_COLL_out_A');

f15 = figure;
figure(f15);
hold on
plot(QuadHash_out_2(:,1), 'LineWidth',1.5);
plot(QuadHash_out_2(:,2), 'LineWidth', 1.0);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Avg Time', 'Search Avg Time', 'Location', 'northwest');

% Output the plot to EPS for LATEX
print(f15, '-depsc', 'QuadHash_INS_out_B');

f16 = figure;
figure(f16);
hold on
plot(QuadHash_Collision_2, 'LineWidth', 1.5);
plot(QuadHash_Search_2, 'LineWidth', 1.5);
ylabel('Collisions');
xlabel('Number of Elements in Data Structure (10^2)');
legend('Insert Collisions', 'Search Collisions', 'Location', 'northwest');


% Output the plot to EPS for LATEX
print(f16, '-depsc', 'QuadHash_COLL_out_B');

%% SUMMARY PLOTS -> BST, LL, and LLHash
f17 = figure;
figure(f17);
hold on
plot(BST_out_1(:,1), 'LineWidth',1.5);
plot(LL_out_1(:,1), 'LineWidth',1.5);
plot(LLHash_out_1(:,1), 'LineWidth', 1.5);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('BST Insert Avg Time', 'Linked List Insert Avg Time', 'Chaining Hash Insert Avg Time', 'Location', 'northwest');
set(gca, 'YScale', 'log')

% Output the plot to EPS for LATEX
print(f17, '-depsc', 'InsertSummary');

f18 = figure;
figure(f18);
hold on
plot(BST_out_1(:,2), 'LineWidth',1.5);
plot(LL_out_1(:,2), 'LineWidth',1.5);
plot(LLHash_out_1(:,2), 'LineWidth', 1.5);
ylabel('Microseconds per Operation');
xlabel('Number of Elements in Data Structure (10^2)');
legend('BST Avg Search Time', 'Linked List Avg Search Time', 'Chaining Hash Avg Search Time', 'Location', 'northwest');
set(gca, 'YScale', 'log')

% Output the plot to EPS for LATEX
print(f18, '-depsc', 'SearchSummary');
