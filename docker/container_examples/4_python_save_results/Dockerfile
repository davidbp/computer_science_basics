
FROM python:3.5


# Install numpy
RUN pip install numpy && pip install pandas && pip install sklearn

# Set working directory to /app and copy the current dir
WORKDIR /app
COPY . /app

# run the python code
CMD ["python", "model_training.py"]