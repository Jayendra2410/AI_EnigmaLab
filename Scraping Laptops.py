from bs4 import BeautifulSoup
import openpyxl

with open('laptop_final20.html', 'r', encoding='utf-8') as file:
    html_content = file.read()

soup = BeautifulSoup(html_content, 'html.parser')

divs = soup.find_all('div', class_='puis-card-container s-card-container s-overflow-hidden aok-relative puis-include-content-margin puis puis-v3o2zdxdjaxcix2e3x4m988k53u s-latency-cf-section puis-card-border')

Names = []
Prices = []
Reviews = []

for div in divs:
    name_span = div.find('span', class_='a-size-medium a-color-base a-text-normal')
    if name_span:
        Names.append(name_span.text)
    else:
        Names.append("")
    price_span = div.find('span', class_='a-price-whole')
    if price_span:
        Prices.append(price_span.text)
    else:
        Prices.append("")
    review_span = div.find('span', class_='acr-average-stars-rating-text')
    if review_span:
        Reviews.append(review_span.text)
    else:
        Reviews.append("")

workbook = openpyxl.Workbook()
sheet = workbook.active
sheet.title = 'Laptops'
sheet['A1'] = 'Name'
sheet['B1'] = 'Price'
sheet['C1'] = 'Review'

for idx, (name, price, review) in enumerate(zip(Names, Prices, Reviews), start=2):
    sheet[f'A{idx}'] = name
    sheet[f'B{idx}'] = price
    sheet[f'C{idx}'] = review

workbook.save('Laptops_Info20.xlsx')
