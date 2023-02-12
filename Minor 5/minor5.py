import re
def load_records(a):
   file_name=a+'.tsv'
   file=open(file_name)
   data=file.read()
   load_data(data)
   return 0
def load_data(data):
   while True:
       data1=data.split('\n')
       count=0
       i=input('Enter input: ')
       if i.lower()=='quit':
           exit()
       else:
           for j in data1:
               if i in j:
                   ha = j.split('\t')
                   street_address = ha[1]
                   town_state_zipocde = ha[2]+','+ha[0]+','+ha[3]
                   print(street_address)
                   print(town_state_zipocde)
                   count=1
           if count==0:
               a=re.findall('\d+',i)
               if a:
                   print('No records found in this zip code')
               else:
                   print('No records found in this town')

load_records('minor5')