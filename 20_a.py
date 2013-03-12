import string
import os
import fileinput
import sys
import csv

   
print "\n############################################"
print "\n Ducati Memory map file Analysis Tool v0.1"
print "\n############################################"
print "\n"

if len(sys.argv) != 3:
        print "***** Usage syntax Error!!!! *****\n"
        print "Usage:"
        print "map_analysis.py <mapfile> <lib list file>"
        print "\t<mapfile> : map file generated after build"
        print "\t<lib list file>: list of libraries"
        sys.exit(1) # exit
else:
        pass

print "\nAlnalyzing...\n"

map_file_name = sys.argv[1] # map file name
lib_list_file = sys.argv[2] # Library name list file


# pre-defined section names in the existing map file
# this aspect would be changing as and when new type of sections are added. 
text_section = ".text"
bss_section  = ".bss"
const_section = ".const"

# respective memory size (sectionwise)
text_section_mem = 0
bss_section_mem = 0
const_section_mem = 0



#open output CVS file
w = csv.writer(open('analysis_output.csv','w'))



#open library name list file
file_lib_list = open(lib_list_file)

# read first line in that file
lib_name = file_lib_list.readline()

# for every line (library name)
while lib_name:

        #print len(lib_name)
        lib_name = lib_name[:-1]
        #print len(lib_name)

        # open map file 
        file_map = open(map_file_name)
        sum = 0
        obj_string = "this should not be in map file"
        line = file_map.readline()
        while line:
                #print line
                #print lib_name
                if lib_name in line:
                        #line =line.replace(stext, rtext)
                        #if lib_name in line:
                        #print "ok"
                        s  = line.split
                        array_size =  len(s())

                        obj_string = s()[array_size-2]
                        mem = int((s()[1]),16)
                        if text_section in line:
                                text_section_mem = text_section_mem + mem
                        else:
                                pass
                        if bss_section in line:
                                bss_section_mem = bss_section_mem + mem
                        else:
                                pass
                        if const_section in line:
                                const_section_mem = const_section_mem + mem
                        else:
                                pass

                else:
                        if obj_string in line:
                                s  = line.split
                                mem = int((s()[1]),16)

                                if text_section in line:
                                        text_section_mem = text_section_mem + mem
                                else:
                                        pass
                                if bss_section in line:
                                        bss_section_mem = bss_section_mem + mem
                                else:
                                        pass
                                if const_section in line:
                                        const_section_mem = const_section_mem + mem
                                else:
                                        pass

                        else:
                                pass
                        pass
                line = file_map.readline()
                pass
        pass
        file_map.close()
        #print lib_name, text_section, text_section_mem, bss_section, bss_section_mem, const_section, const_section_mem
        row_field = [lib_name, text_section, text_section_mem, bss_section, bss_section_mem, const_section, const_section_mem]
        w.writerow(row_field)
        lib_name = file_lib_list.readline()
file_lib_list.close()
print "\nFinished !"
print "\nPlease find the analysis results in 'analysis_output.csv'"
pass


