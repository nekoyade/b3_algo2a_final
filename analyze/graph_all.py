import matplotlib.pyplot as plt
import numpy as np


def make_graph(attr, order, arrs):
    fig = plt.figure()
    ax = fig.add_subplot(111)

    sort_map = {
        "bubble": "Bubble",
        "select": "Selection",
        "insert": "Insert",
        "shell": "Shell",
        "quick": "Quick",
        "merge": "Merge",
        "heap": "Heap",
    }

    for label, data in arrs.items():
        leg = sort_map[label]
        ax.plot(data[:, 0], data[:, 1], marker="o", label=leg)

    ax.set_xscale("log")
    ax.set_yscale("log")

    ax.legend()
    ax.set_xlabel("Number of sorted cities")
    ax.set_ylabel("Sorting time / sec")

    plt.savefig(f"all/{attr}{order}.png")


if __name__ == "__main__":
    sorts = [
        "bubble", "select", "insert", "shell", "quick", "merge", "heap"
    ]
    for attr in ["p", "a", "n"]:
        for order in ["d", "a"]:
            arrs = {}
            for sort in sorts:
                filename = f"{sort}_{attr}{order}_03.csv"
                data = np.loadtxt(f"data/{filename}", delimiter=",")
                arrs[sort] = data

            make_graph(attr, order, arrs)
