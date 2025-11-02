# Sub-Task 1: Initialize Logging
# Logs will appear ON SCREEN + also save to process_log.txt

import logging

# Create logger object
logger = logging.getLogger()
logger.setLevel(logging.INFO)

# File handler (saves logs)
file_handler = logging.FileHandler('process_log.txt')

# Stream handler (prints logs on screen in Colab)
stream_handler = logging.StreamHandler()

# Log format
formatter = logging.Formatter('%(asctime)s - %(processName)s - %(message)s')
file_handler.setFormatter(formatter)
stream_handler.setFormatter(formatter)

# Add handlers
logger.addHandler(file_handler)
logger.addHandler(stream_handler)

logging.info("✅ Logging system initialized successfully!")

