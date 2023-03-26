import sys
input = sys.stdin.readline

grade_dict = {"A+": 4.5,"A0":4.0,"B+":3.5,"B0":3.0,"C+":2.5,"C0":2.0,"D+":1.5,"D0":1.0,"F":0.0}

sum_credit = 0
sum_grade = 0

for _ in range(20):
    name, credit, grade = input().rstrip().split(" ")
    if grade == "P":
        continue
    sum_credit += float(credit)
    sum_grade += float(credit) * grade_dict[grade]

print(round(sum_grade / sum_credit,6))