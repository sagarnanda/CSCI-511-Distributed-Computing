class Media(object):
   def __init__(self, call_no, title, subject):
      self.callNumber = call_no
      self.title = title
      self.subject = subject

   def display(self):
      print ("Call Number: ", self.callNumber, "Title: ", self.title, "Subject: ", self.subject)
   
   def comp_call_no(self, call_no):
      if call_no in self.callNumber:
         return True
      else:
         return False

   def comp_title(self, title):
      if title in self.title:
         return True
      else:
         return False

   def comp_subjects(self, subject):
      if subject in self.subject:
         return True
      else:
         return False
