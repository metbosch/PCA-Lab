#!/usr/local/bin/python

import sys, subprocess
from subprocess import call

MIN_ARGS = 5

def usage():
	close('USAGE: Exec_original Exec2_optimized NUM_EXECS NUM_PARAMS [PRAM 1] [PARAM 2] ...')

def close(message):
	print message + "\n"
	sys.exit(1)

def getExecTime(string):
	line = string.split('\n', 1)[0]
	parts = line.split(' ')
	time = float(parts[1])
#	minutes = float(parts[0].split('\t')[1])
	return time
		

def main():
	if (len(sys.argv) < MIN_ARGS):
		usage()

	NUM_EXECS  = int(sys.argv[3])
	NUM_PARAMS = int(sys.argv[4])
	EXE_PARAMS = ""
	if (len(sys.argv) != MIN_ARGS + NUM_PARAMS):
		usage()
	else:
		# Generate string of params for executions
		i = 0
		while (i < NUM_PARAMS):
			EXE_PARAMS += sys.argv[MIN_ARGS + i] + ' '
			i += 1
		
		print "Generating correct output"
		# Save the original output of execution
		p1 = subprocess.Popen("./" + sys.argv[1] + " " + EXE_PARAMS, stdout=subprocess.PIPE, shell=True)
		(out1, err1) = p1.communicate()
		
		print "Generating optimized output"
		# Save the optimized output of execution
		p2 = subprocess.Popen("./" + sys.argv[2] + " " + EXE_PARAMS, stdout=subprocess.PIPE, shell=True)
		(out2, err2) = p2.communicate()
		
		# Compare the outputs
		if out1 != out2:
			close("ERROR - Outputs do not match")

		print "Outputs are equal"

		# Clean the output file
		with open("script.out", "w") as my_file:
				my_file.write("orig\toptim\n")
		
		original_time = 0.0
		total_time = 0.0
		last_original = 0.0
		last_optimized = 0.0
		i = 0
		while i < NUM_EXECS:
			print "Starting the execution number: " + str(i)
			print "  Start Original"
			p1 = subprocess.Popen("time -p ./" + sys.argv[i%2 + 1] + " " + EXE_PARAMS + ">/dev/null", stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
			(out1, err1) = p1.communicate()
			if (i%2):
				last_optimized = getExecTime(err1)
				total_time += last_optimized
			else:
				last_original = getExecTime(err1)
				original_time += last_original
			
			print "  Start Optimizated"
			# The execution of program prints in stdout (out2) and time program prints in stderr (err2)
			# If any error happens on program execution, their error output is terminal
			p2 = subprocess.Popen("time -p ./" + sys.argv[(i+1)%2 + 1] + " " + EXE_PARAMS + ">/dev/null", stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
			(out2, err2) = p2.communicate()
			if (i%2):
				last_original = getExecTime(err2)
				original_time += last_original
			else:
				last_optimized = getExecTime(err2)
				total_time += last_optimized
			
			# Adds to file the execution time
			with open("script.out", "a") as my_file:
				my_file.write(str(last_original) + '\t' + str(last_optimized) + '\n')
			i += 1

		# Adds to file the average execution time and speed-up
		with open("script.out", "a") as my_file:
			my_file.write("Average:\n" + str(original_time/NUM_EXECS) + "\t" + str(total_time/NUM_EXECS) + '\n')
			my_file.write("Speed-up: " + str((original_time/NUM_EXECS)/(total_time/NUM_EXECS)) + '\n')
		print "Speed-up: " + str((original_time/NUM_EXECS)/(total_time/NUM_EXECS))

if __name__ == '__main__':
	main()
 