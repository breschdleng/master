import pandas as pd
import argparse
import numpy as np
import decimal
import os
from collections import Counter


#Parse all arguments
def parse_args():
    parser = argparse.ArgumentParser(description = 'Make Sure a "knockout" and "credit" coloum name is present. Otherwise the program will not work\ .For eg. type like this: python Tally_Passbook.py file1.xls')
    parser.add_argument(dest ='file_path', help='enter fullpath of the file')
    args = parser.parse_args() 
    return args

if __name__=="__main__":

    args = parse_args() 

if args.file_path is None:
   raise IOError(('No File is found, check if the file exists or give correct path again..check for spelling mistakes in the filename'.format(args.file_path)))
#if args.col_tally is None:
 #  raise IOError(('Not a valid column totally'.format(args.file_path)))

df = pd.read_excel(args.file_path)

#df['credit'] = df['credit'].str.replace('$', '')
dir_path = os.path.dirname(os.path.realpath(args.file_path))


field = "knockout"
has_knockout_field = [s for s in df.columns.values if field in str(s)]

if not has_knockout_field:
      raise IOError ("Make Sure a 'knockout' column names is present. NOT IN CAPITAL LETTERS, write knockout in the excel field in small letters,  Otherwise the program will not work")

field = "credit"
has_credit_field = [s for s in df.columns.values if field in str(s)]

if not has_credit_field:
      raise IOError ("Make Sure a 'credit' column name is present. NOT IN CAPITAL LETTERS, write credit in the excel field in small letters,  otherwise the program will not work. All ")


#length of the dataframe
l = len(df)

# find where the search string exists in the excel rows, we are lookingfor a string such as "Tally"
found_row = 0
found_str = ""
#sort the dataframe using the col field knockout
df_sorted = df.sort_values('knockout')
df_sorted = df_sorted.reset_index(drop=True)

#take the first value as ref string
ref_str = df_sorted.loc[1, 'knockout']

#iterate over the all the rows in the dataframe and look for the indexof the refstring 
for i in range(l):
    if df_sorted['knockout'][i]!=ref_str:
    #found ref string
        found_row = i
        found_str = df_sorted['knockout'][i]
        break

df_str = df_sorted['credit'].astype(float)
temp = df_str.values

#convert the dataframes to two numpy arrays, both to be searched against each other
A_str=temp[0:found_row]
B_str=temp[found_row:l]

res_A_not_in_B = []

#perform the match from one list against the other, res contains allthe elements in A not in B
acount =  Counter(A_str)

bcount = Counter(B_str)                            #print(A_str[1:10])
res_A_not_in_B = list((acount - bcount).elements())#print(B_str[1:10])
#print(res_A_not_in_B)


df_A_not_in_B = pd.DataFrame({ref_str:res_A_not_in_B})
out_filename = dir_path+'/Exceptions_in_'+args.file_path.split('.')[0]+'.xlsx'

writer1 = pd.ExcelWriter(out_filename)
df_A_not_in_B.to_excel(writer1, "Sheet1",index=False)

res_B_not_in_A = []
res_B_not_in_A = list((bcount - acount).elements())

df_B_not_in_A = pd.DataFrame({found_str:res_B_not_in_A})
df_B_not_in_A.to_excel(writer1, startrow=len(df_A_not_in_B)+2, index=False)
writer1.close()
print('Success. Two files are written to your current directory!')
print("Difference between original PBCR and tally records is {0}".format(sum(A_str)-sum(B_str)))
print("Difference between python generated PBCR and tally records is {0}".format(sum(res_A_not_in_B)-sum(res_B_not_in_A)))
