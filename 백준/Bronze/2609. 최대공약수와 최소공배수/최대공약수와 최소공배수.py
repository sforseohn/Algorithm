# 유클리드 호제법: a와 b의 최대공약수는 a%b와 b의 최대공약수와 같다
def gcdIter(a, b): 
    while(b):
        a %= b;
        a, b = b, a
    return a;

a, b = map(int, input().split()) # 가지고 있는 랜선의 수, 필요한 랜선의 수

gcd = gcdIter(max(a, b), min(a, b))
lcm = int(a*b / gcd) # 최소공배수 = 두 수의 곱 / 최대공약수
    
print(gcd)
print(lcm)