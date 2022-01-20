# -*- coding:utf-8 -*-
"""
作者: GrandeLai
日期: 2022年01月20日
"""
import random
import csv

#读取
with open('Prostate_Cancer.csv','r') as file:
    reader=csv.DictReader(file) #以字典的方式读取
datas=[row for row in reader] #把每一行抽出来放进datas里面

#分组
random.shuffle(datas) #每次测试都打乱顺序，是每次运行数据都不太一样
n=len[datas]//3
test_set=datas[0:n] #测试集
train_set=datas[n:] #训练集

#KNN
#算距离的函数,用欧式距离
def distance(d1,d2):
    res=0
    for key in("diagnosis_result","radius",	"texture","perimeter","area","smoothness","compactness","symmetry","fractal_dimension"):
        res+=(flout(d1[key])-flout(d2[key]))**2
    return res**0.5

#定义一个KNN函数
K=5
def KNN(data):
    #1.距离
    res=[
        {"result":train["diagnosis_result"],"distance":distance(data,train)}
    ]

    #2.升序排序
    res=sorted(res,key=lambda item:['distance'])

    #3.取前K个
    res2=res[0:K]

    #4.加权平均
    result={'B':0,'M':0} #赋予权重

    #算总距离
    sum=0
    for i in res2:
        sum+=r['distance']

    for i in res2:
        result[r['result']]+=1-r['distance']/sum #代表现在结果给B还是M加权

    if result['B']>result['M']:
        return 'B'
    else:
        return 'M' #给出结果

#测试
correct=0
for test in test_set: #把测试集里的每一项都拿出来测一测
    result=test['diagnosis_result'] #是result的真实结果
    result2=knn(test)

    if result==result2: #判断预测是否准确
        correct+=1

