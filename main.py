import smtplib
import requests
import os
from dotenv import load_dotenv # type: ignore

load_dotenv()

EMAIL='mwangibrandon2@gmail.com'
with smtplib.SMTP('smtp.gmail.com') as connection: #opening connection to smtp.gmail.com
    print('Encrypting Connection')
    connection.starttls() #TLS Encryption Security to gmail
    print('Logging in to:', EMAIL)
    connection.login(user=EMAIL, password='') #Log in to Gmail using the App Key
    print('Sending Email to:',EMAIL, 'from:', EMAIL)
    connection.sendmail(
        from_addr=EMAIL,
        to_addrs=EMAIL,
        msg='This is a Test email'        
    ) #Send Email by passing from_address, recepient_address and message
    print('Email sent. Closing Connection')
    connection.close()

