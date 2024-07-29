from setuptools import setup, Extension

def main():
    setup(name="Rotate",
          version="1.0.0",
          description="Python interface for the rotation C function",
          author="AnGlonchas",
          ext_modules=[Extension("Rotate", ["rotatemodule.c"])])

if __name__ == "__main__":
    main()