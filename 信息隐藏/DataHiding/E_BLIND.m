clear ; close all; clc;
[Filename, Pathname] = uigetfile('*.jpg;*.jpeg;*.png;*.bmp','请选择图片');
str1 = [Pathname Filename];  
c0 = imread(str1);
[row, col] = size(c0);
wr = randn(size(c0));
m = 1;
a = 1;
cw = c0;
for i = 1 : row
    for j = 1 : col
        t = c0(i, j) + a * (2 * m - 1) * wr(i, j);
        if(t > 255)
            t = 255;
        elseif(t < 0)
            t = 0;
        end
        cw(i, j) = t;
    end
end


figure;
subplot(221), imshow(c0),  title("原始图像");
subplot(223), imshow(wr),  title("水印图像");
%subplot(223), plot(wr, ),  title("水印曲线");
subplot(222), imshow(cw),  title("加水印后图像");







% 检测
res = 0;
   
for i = 1 : 100
    at = rand(size(c0)) > 0.25;
    at = cw * at;
    zlc = 0.0;
for i = 1 : row
    for j = 1 : col
        zlc = zlc + double(cw(i, j)) * double(wr(i, j)) * double(at(i, j));
    end
end
ans = zlc / (row * col);

T = 0.7;

if(ans  > T)
    ans = 1;
elseif(ans < -T)
    ans = 0;
else
    ans = -1;
end
res = res + ans;
end
res

