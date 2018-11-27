
FROM aghorbani/spark:2.1.0
MAINTAINER Asghar Ghorbani [https://de.linkedin.com/in/aghorbani]

# Configure environment
ENV CONDA_DIR /opt/conda
ENV PATH $CONDA_DIR/bin:$PATH

#Install Anaconda
RUN curl -s https://repo.continuum.io/archive/Anaconda3-4.2.0-Linux-x86_64.sh -o anaconda.sh && \
    chmod a+x anaconda.sh && \
    ./anaconda.sh -b -p $CONDA_DIR && \
    rm ./anaconda.sh && \
    conda install pyspark

RUN python -m nltk.downloader punkt

#Environment vaiables for Spark to use Anaconda Python and iPython notebook
ENV PYSPARK_PYTHON $CONDA_DIR/bin/python3
ENV PYSPARK_DRIVER_PYTHON $CONDA_DIR/bin/jupyter
ENV PYSPARK_DRIVER_PYTHON_OPTS "notebook --no-browser --port=8888 --ip='*'"

ENV PYTHONPATH=$SPARK_HOME/python/:$PYTHONPATH
ENV PYTHONPATH=$SPARK_HOME/python/lib/py4j-0.8.2.1-src.zip:$PYTHONPATH

#iPython port
EXPOSE 8888

WORKDIR $SPARK_HOME


# Set working directory to /app and copy the current dir
WORKDIR /app
COPY . /app

