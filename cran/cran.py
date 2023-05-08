import threading
import os
from time import sleep

def write_to_c_file(filename, text):
    with open(filename, 'a') as cfile:
        cfile.write(text + '\n')

def write_hello_to_c_file(filename):
    while not stop_thread.is_set():
        write_to_c_file(filename, 'printf("Hello, I\'m being used to test an automatic program\\n");')
        sleep(0.1)

if __name__ == '__main__':
    file_name = input('Enter the name of the C file: ') + '.c'

    if not os.path.exists(file_name):
        with open(file_name, 'w') as cfile:
            pass

    stop_thread = threading.Event()
    writer_thread = threading.Thread(target=write_hello_to_c_file, args=(file_name,))

    print("Press any key to stop writing to the file.")
    writer_thread.start()

    try:
        input()
    except KeyboardInterrupt:
        pass

    stop_thread.set()
    writer_thread.join()

    print(f"Stopped writing to {file_name}")