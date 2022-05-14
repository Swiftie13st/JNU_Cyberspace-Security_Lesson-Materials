clear all;
clc;
[Filename, Pathname] = uigetfile('*.jpg;*.jpeg;*.png;*.bmp','请选择图片');
str1 = [Pathname Filename];  
c0 = imread(str1);
attack = rand(size(c0)) > 0.25
