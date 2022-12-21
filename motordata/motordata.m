t_s=0.02;
t_start=0;
t_end=1732.8;
p = polyfit(longtime0529.time,longtime0529.speed,1);
y1 = polyval(p,longtime0529.time);
figure(1)
plot(longtime0529.time,longtime0529.speed)
figure(2)
plot(longtime0529.time,y1)
yf=fft(longtime0529.speed);
figure(3)
plot(longtime0529.time,yf)
Druation = t_end -t_start;   %计算采样时间
Sampling_points = Druation/t_s +1;  %采样点数，fft后的点数就是这个数
f_s = 1/t_s; %采样频率
f_x = 0:f_s/(Sampling_points -1):f_s;  %注意这里和横坐标频率对应上了，频率分辨率就是f_s/(Sampling_points -1)
t2 = f_x-f_s/2;
shift_f = abs(fftshift(yf));
figure(4)
plot(f_x,yf);title('fft transform');

















%plot(data1.time,data1.speed);
%plot(switchduty1.time,switchduty1.speed);
% avg = 0;
% last = 0;
% pre = 0;
% ppre =0;
% pppre=0;
% ppppre=0;
% pppppre=0;
% del = 0;
% sum =0;
% %ta=table(time,speed,'RowNames',LastName);
% an=zeros(50000,2);
% for i=1:1:50000
%     sum=sum+data1.speed(i)-del;
%     avg=sum;
%     an(i,1)=data1.time(i);
%     an(i,2)=avg;
%     last=data1.speed(i);
%     pre=last;
%     ppre=pre;
%     pppre=ppre;
%     ppppre=pppre;
%     pppppre=ppppre;
%     del=pppppre;
% end
% mean(data1.speed)
% plot(an(:,1),an(:,2))
%plot(data1.time,data1.speed)




