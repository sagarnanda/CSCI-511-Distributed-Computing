from Media import Media
from Book import Book
from Film import Film
from Video import Video
from Periodic import Periodic


class SearchEngine(object):
   def __init__(self):
      self.CardCatalog = list()
      read_file = open("book.txt", "r")
      for line in read_file:
         self.CardCatalog.append(Book(*line.strip().split('|')))
      read_file.close()
      #Reading video.txt
      read_file = open("video.txt", "r")
      for line in read_file:
         self.CardCatalog.append( Video( *line.strip().split('|')))
      read_file.close()
      #Reading periodic.txt
      read_file = open("periodic.txt", "r")
      for line in read_file:
         self.CardCatalog.append( Periodic( *line.strip().split('|')))
      read_file.close()
      #Reading film.txt
      read_file = open("film.txt", "r")
      for line in read_file:
         self.CardCatalog.append( Film( *line.strip().split('|')))
      read_file.close()

   def search_by_call_no(self, call_no):
      results = list()
      for media in self.CardCatalog:
         re = media.comp_call_no(call_no)
         if re == True:
            results.append(media)
      return results

   def search_by_subjects(self, subject):
      results = list()
      for media in self.CardCatalog:
         re = media.comp_subjects(subject)
         if re == True:
            results.append(media)
      return results

   def search_by_title(self, title):
      results = list()
      for media in self.CardCatalog:
         re = media.comp_title(title)
         if re == True:
            results.append(media)
      return results


   def search_by_other(self, search):
      results = list()
      for media in self.CardCatalog:
         re = media.compareByOther(search)
         if re == True:
            results.append(media)
      return results

   def display(self,results):
      for media in results:
         media.display()

