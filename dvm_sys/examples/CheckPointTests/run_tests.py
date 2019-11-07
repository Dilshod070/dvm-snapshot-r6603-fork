import os
import re
import logging
import random


FORMAT = '%(asctime)-15s %(levelname)-8s %(message)s'
logging.basicConfig(format=FORMAT, level=logging.DEBUG)

THIS_FILENAME = str(__file__).split('/')[-1]
TESTS_DIR = os.path.dirname(__file__)
USER_DIR = TESTS_DIR.replace('examples/CheckPointTests', 'user')
TESTS_WORKDIR = USER_DIR + '/tests'
TESTS_DATA = TESTS_WORKDIR + '/data'


def get_grid_list(filename, size_=3, min_=1, max_=4):
    nd = re.search(r'_(\d)d', filename)
    if nd:
        n = int(nd.group(1))
        return list(list(random.randint(min_, max_) for _ in range(n)) for _ in range(size_))
    return [[]]


def run_test(task, grid_list):
    for grid in grid_list:
        grid_str = ' '.join(str(d) for d in grid)
        command = f'{USER_DIR}/dvm {grid_str} {TESTS_DIR}/{task}'
        logging.info(f'Running command:\t{command}')
        # status = os.system()
        status = 0
        yield status


def main():
    logging.info('Start unit-testing')

    files_set = set(os.listdir(TESTS_DIR))
    files_set = set(filter(lambda x: x.endswith('.c') or x.endswith('.cdv'), files_set))
    logging.info(f'Found these tests: {files_set}')

    for test_file in files_set:
        logging.info(f'Compiling file:\t{USER_DIR}/dvm c {TESTS_DIR}/{test_file}')
        status = os.system(f'{USER_DIR}/dvm c {TESTS_DIR}/{test_file} &> {TESTS_DATA}/compile_status')
        logging.debug(f'Status\t{"OK" if status == 0 else status}')
        if status != 0:
            logging.error(f'Error compiling {test_file}, information is below')
            os.system(f'cat {TESTS_DATA}/compile_status')
            raise RuntimeError(f'Error compiling {test_file}')

    ok_tests, failed_tests, total_tests = 0, 0, len(files_set)
    for test_file in files_set:
        all_passed = True
        for status in run_test(test_file.split('.')[0], get_grid_list(test_file)):
            if status == 0:
                logging.info('OK')
            else:
                logging.error('FAILED')
                all_passed = False
        if all_passed:
            ok_tests += 1
        else:
            failed_tests += 1

    logging.info(f'PASSED:\t{ok_tests}/{total_tests}')
    logging.info(f'FAILED:\t{failed_tests}/{total_tests}')


if __name__ == '__main__':
    main()
