class PriorityQueue {
  #compare = (a, b) => a - b;
  #heap = new Array(64);
  #size = 0;

  constructor(array, comparator) {
    if (array) {
      this.heapify(array);
    }

    if (comparator) {
      this.#compare = comparator;
    }
  }

  get length() {
    return this.#size;
  }

  insert(value) {
    const heap = this.#heap;
    const pos = ++this.#size;
    heap[pos] = value;

    if (heap.length === pos) {
      heap.length *= 2;
    }

    this.percolateUp(pos);
  }

  peek() {
    return this.#heap[1];
  }

  percolateDown(pos) {
    const compare = this.#compare;
    const heap = this.#heap;
    const size = this.#size;
    const item = heap[pos];

    while (pos * 2 <= size) {
      let childIndex = pos * 2 + 1;

      if (childIndex > size || compare(heap[pos * 2], heap[childIndex]) < 0) {
        childIndex = pos * 2;
      }

      const child = heap[childIndex];

      if (compare(item, child) <= 0) {
        break;
      }

      heap[pos] = child;
      pos = childIndex;
    }

    heap[pos] = item;
  }

  percolateUp(pos) {
    const heap = this.#heap;
    const compare = this.#compare;
    const item = heap[pos];

    while (pos > 1) {
      const parent = heap[(pos / 2) | 0];

      if (compare(parent, item) <= 0) {
        break;
      }

      heap[pos] = parent;
      pos = (pos / 2) | 0;
    }

    heap[pos] = item;
  }

  removeAt(pos) {
    const heap = this.#heap;
    const size = --this.#size;
    heap[pos] = heap[size + 1];
    heap[size + 1] = undefined;

    if (size > 0 && pos <= size) {
      if (pos > 1 && this.#compare(heap[(pos / 2) | 0], heap[pos]) > 0) {
        this.percolateUp(pos);
      } else {
        this.percolateDown(pos);
      }
    }
  }

  shift() {
    const heap = this.#heap;
    const value = heap[1];

    if (value === undefined) {
      return;
    }

    this.removeAt(1);

    return value;
  }

  heapify(array) {
    this.#heap = new Array(array.length + 1);
    this.#size = array.length;

    for (let i = 0; i < array.length; i++) {
      this.#heap[i + 1] = array[i];
    }

    for (let i = Math.floor(this.#size / 2); i > 0; i--) {
      this.percolateDown(i);
    }
  }
}



function solution(scoville, K) {
    const heap = new PriorityQueue(scoville)
    let count = 0
    
    while (heap.length) {
        const top = heap.shift()
        
        if (top >= K) {
            return count
        }
        
        if (heap.length) {
            heap.insert(top + heap.shift() * 2)
            count += 1
        }
    }
    
    return -1
}