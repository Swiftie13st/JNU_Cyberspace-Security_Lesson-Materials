[Filename, Pathname] = uigetfile('*.jpg;*.jpeg;*.png','请选择图片');
str1 = [Pathname Filename];  
c0 = imread(str1);
[row, col] = size(c0);
wr = randn(size(c0));
m = round(rand(size(c0)));
a = 1;
wm = wr * a;
cw = double(c0);

for i = 1 : row
    for j = 1 : col
        if(m(i, j) == 1)
            cw(i, j) = cw(i, j) + wm(i, j);
        else
            cw(i, j) = cw(i, j) - wm(i, j);
        end
    end
end

figure;
subplot(221), imshow(c0),  title("原始图像");
subplot(223), imshow(wr),  title("水印图像");
%subplot(223), plot(wr, ),  title("水印曲线");
subplot(222), imshow(cw),  title("加水印后图像");


