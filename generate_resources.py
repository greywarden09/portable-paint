#!/usr/bin/env python3

import xml.etree.ElementTree as ET

from os import listdir
from os.path import isfile, join

rcc = ET.Element("RCC")
qresource = ET.SubElement(rcc, "qresource", attrib={"prefix": "resources"})

for resource in [f for f in listdir('resources') if isfile(join('resources', f))]:
    ET.SubElement(qresource, "file", attrib={"alias": resource}).text = f"resources/{resource}"

tree = ET.ElementTree(rcc)

with open("resources.qrc", "wb") as f:
    tree.write(f)
