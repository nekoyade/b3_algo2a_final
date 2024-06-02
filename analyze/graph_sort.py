import matplotlib.pyplot as plt
import numpy as np


def make_graph(sort, arrs):
    fig = plt.figure()
    ax = fig.add_subplot(111)

    attr_map = {
        "p": "Population",
        "a": "Latitude",
        "n": "Longitude",
    }
    order_map = {
        "d": "Descend",
        "a": "Ascend",
    }

    for label, data in arrs.items():
        leg = f"{attr_map[label[0]]}/{order_map[label[1]]}"
        ax.plot(data[:, 0], data[:, 1], marker="o", label=leg)

    ax.set_xscale("log")
    ax.set_yscale("log")

    ax.legend()
    ax.set_xlabel("Number of sorted cities")
    ax.set_ylabel("Sorting time / sec")

    plt.savefig(f"sort/{sort}.png")


if __name__ == "__main__":
    sorts = [
        "bubble", "select", "insert", "shell", "quick", "merge", "heap"
    ]
    for sort in sorts:
        arrs = {}
        for attr in ["p", "a", "n"]:
            for order in ["d", "a"]:
                filename = f"{sort}_{attr}{order}_03.csv"
                data = np.loadtxt(f"data/{filename}", delimiter=",")
                arrs[f"{attr}{order}"] = data

        make_graph(sort, arrs)
