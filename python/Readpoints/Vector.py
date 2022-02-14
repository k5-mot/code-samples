 #! /usr/bin/env python
# coding:utf-8
import sys
import math
import copy

def isnum(n):
    """ Check if n is a number """
    return type(n) in (int, float, complex)

def make_vector(*ele, **key):
    """ Make an instance of Vector """
    if ele:
        return Vector(ele)
    elif 'value' in key and 'dimension' in key:
        return Vector([key['value'] for x in range(key['dimension'])])
    else:
        raise KeyError('Key should be \'dimension\' and \'value\'.')

class Vector(tuple):
    def __add__(self, right):
        """ Addition Operator """
        if isinstance(right, Vector):
            if len(self) == len(right):
                return Vector([xl + xr for xl, xr in zip(self, right)])
            else:
                raise ValueError('Same dimension is required.')
        else:
            raise ValueError('Vector class is required.')

    def __sub__(self, right):
        """ Subtraction Operator """
        return self.__add__(-right)

    def __mul__(self, right):
        """ Multiplication Operator """
        if isinstance(right, Vector):
            if len(self) == len(right):
                return sum([xl * xr for xl, xr in zip(self, right)])
            else:
                raise ValueError('Same dimension is required.')
        elif isnum(right):
            return Vector([x * right for x in self])
        else:
            raise TypeError('Vector or number is required.')

    def __pos__(self):
        """ Positive Operator """
        return copy.copy(self)

    def __neg__(self):
        """ Negative Operator """
        return Vector([-x for x in self])

    def __abs__(self):
        """ Absolute Operator """
        return math.sqrt(sum([x * x for x in self]))

    def normalize(self):
        norm = abs(self)
        return Vector([x / norm for x in self])

    def __str__(self):
        """ String Operator """
        return tuple.__str__(self)


def main(argv=sys.argv):
    v1 = Vector([1, 2, 3])
    v2 = Vector([2.0, 3.0, 4.0])
    v3 = Vector([1 + 2j, 2 + 3j, 4 + 5j])
    print('v1 = Vector([1, 2, 3]) = ', v1)
    print('v2 = Vector([2.0, 3.0, 4.0]) = ', v2)
    print('v3 = Vector([1 + 2j, 2 + 3j, 4 + 5j]) = ', v3)
    print('+v1 = ', +v1)
    print('-v1 = ', -v1)
    print('v2 + v1 = ', v2 + v1)
    print('v2 - v1 = ', v2 - v1)
    print('v1 * v2 = ', v1 * v2)
    print('3 * v1 = ', 3 * v1)
    print('v1 * 3 = ', v1 * 3)
    print('v1 == v2 ', v1 == v2)
    print('abs(v1) = ', abs(v1))
    print('v1.normalize() = ', v1.normalize())
    v1 += v2
    print('v1 += v2 -> v1', v1)
    v1 -= v2
    print('v1 -= v2 -> v1', v1)
    print('make_vector(1,2,3,4) =', make_vector(1,2,3,4))
    print('make_vector(dimension=5, value=0) =', make_vector(dimension=5, value=0))
    print('v3 + make_vector(dimension=len(v3), value= 1+2j) = ', v3 + make_vector(dimension=len(v3), value= 1+2j))
    print('repr(v1) = ', repr(v1))
    print('str(v1) = ', str(v1))
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))

