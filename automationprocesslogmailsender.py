import os
import time
import psutil
import urllib.request as urllib2
import schedule
from sys import *
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
import smtplib

def is_connected():
    try:
        urllib2.urlopen("http://216.58.192.142",timeout=10)
        return True
    except urllib2.URLError as err:
        return False
def MailSender(filename,time):
    try:
        fromaddr="wagh2898@gmail.com"
        toaddr="kaustubhkailas@gmail.com"
        msg=MIMEMultipart()
        msg["from"]=fromaddr
        msg["to"]=toaddr
        body="""
        hello %s,
        please find attached document which contains log of running processes
        log file is created at : %s
        this is auto generated mail.
        thnks & regards,
        kaustubh kailas wagh
        """%(toaddr,time)
        subject ="""
        time log generated at: %s
        """%(time)
        msg["subject"]=subject
        msg.attach(MIMEText(body,"plain"))
        attachment = open(filename,"rb")
        p=MIMEBase("application","octet-stream")
        p.set_payload((attachment).read())
        encoders.encode_base64(p)
        p.add_header("Content-Disposition","attachment;filename=%s" % filename)
        msg.attach(p)
        s=smtplib.SMTP("smtp.gmail.com",587)
        s.starttls()
        s.login(fromaddr,"9730832840")
        text=msg.as_string()
        s.sendmail(fromaddr,toaddr,text)
        s.quit()

        print("log file successfully sent through mail")
    except Exception as E:
        print("unable to send mail",E)
def ProcessLog(log_dir = "New folder"):
    listprocess=[]
    if not os.path.exists(log_dir):
        try:
            os.mkdir(log_dir)
        except:
            pass
    separator="-" * 80
    log_path=os.path.join(log_dir,"MarvellousLog")
    f=open(log_path,'w')
    f.write(separator + "\n")
    f.write("Marvellous Infosystems Process Logger :"+time.ctime()+"\n")
    f.write(separator + "\n")
    f.write("\n")
    for proc in psutil.process_iter():
        try:
            pinfo=proc.as_dict(attrs=["pid","name","username"])
            vms=proc.memory_info().vms/(1024*1024)
            pinfo['vms']=vms
            listprocess.append(pinfo);
        except(psutil.NoSuchProcess,psutil.AccessDenied,psutil.ZombieProcess):
            pass
        for element in listprocess:
            f.write("%s\n" % element)
    print("log file is successfully generated at location ,%s"%log_path)
    connected = is_connected()
    if connected:
        startTime=time.time()
        MailSender(log_path,time.ctime())
        endTime=time.time()
        print("took %s seconds to send mail" % (endTime-startTime))
    else:
        print("there is no internet connection")
    
def main():
    print("don")
   # print("Application name :" + argv[0])
    #if(len(argv)!=2):
       # print("Error: Invalid number of arguments")
        #exit()
    
    #if(argv[1]=="-h") or (argv[1]=="-H"):
       # print("this script is used to log record of running processess")
       # exit()
   # if(argv[1]=="-u") or (argv[1]=="-U"):
       # print("usage: ApplicationName absolutepath_of_directory")
      #  exit()
    try:
        schedule.every(1).minutes.do(ProcessLog)
        while True:
            schedule.run_pending()
            time.sleep(1)
    except ValueError:
        print("Error:invalid datatype of input")
    except Exception as E:
        print("Error:invalid input",E)
if __name__ =="__main__":
    main()
            
