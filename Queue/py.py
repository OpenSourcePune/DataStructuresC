import pandas as pd
import json
def makedf(s):
    l = s.split("\n")
    name = l[2]
    vehName = l[6]
    regNo = l[10]
    regDate = l[14]
    data = [['Name',name], ['Vehicle Name',vehName], ['Registration Number',regNo],['Registration date',regDate]]
    df = pd.DataFrame(data)
    return df

def makejson(s):
    l = s.split("\n")
    name = l[2]
    vehName = l[6]
    regNo = l[10]
    regDate = l[14]
    data = [['Name',name], ['Vehicle Name',vehName], ['Registration Number',regNo],['Registration date',regDate]]
    S = json.dumps(data)
    return S

s = ''
'''
---------------------------------
Methods:
1. D = makedf(s)
Description : Takes a string s and processes it
to return a dataframe that is stored in D in this case.
---------------------------------
2. print(S)
Description : Takes a string s and processes it
to return a json object that is stored in S in this case.
---------------------------------
'''
