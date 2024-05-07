from bs4 import BeautifulSoup as bs
import requests as rq

url = "https://www.w3schools.com/css/default.asp"

access = rq.get(url)

soup = bs(access.content)
# print(soup.prettify())

print("This is paragrah")
para = soup.find_all(name='p')
print(para)