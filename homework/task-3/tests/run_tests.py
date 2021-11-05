import subprocess

RUN_EACH_TEST_TIMES = 5
TESTS_COUNT = 6


def run_test(num: int):
    """Запускает тест тum"""
    command = [
        'python3', '-m', 'lang_tool.cli',
        '-f', f'data/test_{num}/input.txt',
        f'data/test_{num}/output_1.txt', f'data/test_{num}/output_2.txt'
    ]
    if num == -1:
        # random
        command = [
        'python3', '-m', 'lang_tool.cli',
        '-n', f'10000',
        f'data/test_rnd/output_1.txt', f'data/test_rnd/output_2.txt'
    ]
    p = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    output = p.communicate()[0].decode('utf-8').split('\n')
    return {
        'Sort time (without read&write)': float(output[0].split(':')[1][1:-1]),
        'Total time (with read&write)': float(output[1].split(':')[1][1:-1])
    }


def run_test_x_times(test_num: int, times: int = RUN_EACH_TEST_TIMES):
    """Усредняет times запусков теста test_num"""
    result = {
        'Sort time (without read&write)': [],
        'Total time (with read&write)': []
    }
    for i in range(times):
        print(f"Running test #{test_num} at {i + 1} time...")
        for key, value in run_test(test_num).items():
            result[key].append(value)
    for key, value in run_test(test_num).items():
        result[key] = sum(result[key]) / times
    return result


if __name__ == '__main__':
    test_results = "# Результаты тестирования\n\n"
    for test in list(range(TESTS_COUNT)) + [-1]:
        result = run_test_x_times(test)
        if test == -1:
            test = 'random10k'
        test_results += f"**Run test #{test}**\n\n"
        for key, value in result.items():
            test_results += f"{key}: `{value:10f}s`<br>\n"
        test_results += "\n\n"
    print(test_results, file=open("README.md", "w"))
