
% Z=(1:100);
% noise=randn(1,100);
% Z=Z+noise;
figure(1);
Z=longtime0529;
scatter(longtime1,Z);

X=[0;0];
P=[1,0;0,1];
F=[1,1;0,1];
Q=[0.0001,0;0,0.0001];
H=[1,0];
R=1;

hold on
figure(2)

for i=1:1000
    X_=F*X;
    P_=F*P*F'+Q;
    K=P_*H'/(H*P_*H'+R);
    X=X_+K*(Z(i)-H*X_);
    P=(eye(2)-K*H)*P_;
    i
    
    scatter(X(1),X(2),'r')    
end


