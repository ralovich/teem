/*
  teem: Gordon Kindlmann's research software
  Copyright (C) 2002, 2001, 2000, 1999, 1998 University of Utah

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "unrrdu.h"
#include "privateUnrrdu.h"

#define INFO "Information about this program and its use"

int
unrrdu_aboutMain(int argc, char **argv, char *me, hestParm *hparm) {
  char buff[AIR_STRLEN_MED], fmt[AIR_STRLEN_MED];
  char par1[] = 
    ("\t\t\t\t"
     "\"unu\" is a command-line interface for much of the functionality "
     "in the \"nrrd\" library for raster data processing. Nrrd is one "
     "library in the \"teem\" group of libraries, which is the software "
     "Gordon Kindlmann writes in support of his research.  More information "
     "about teem and all its constituent libraries is at "
     "<http://www.cs.utah.edu/~gk/teem>.\n"
     );
  char par2[] = 
    ("\t\t\t\t"
     "The utility of unu is mainly as a pre-processing tool for getting "
     "data into a type, encoding, format, or dimensions best suited for some "
     "visualization or rendering task.  Also, slices and projections are "
     "effective ways to visually inspect the contents of a dataset. "
     "Especially useful commands include make, resample, crop, slice, "
     "project, histo, dhisto, quantize, and save.  Full "
     "documentation for each command is shown by typing the command alone, "
     "e.g., \"unu make\".  Unu can process CT and MRI volume "
     "datasets, grayscale and color images, time-varying volumes of "
     "vector fields (5-D arrays), and more.  Currently supported formats are "
     "plain text files (2-D float arrays), "
     "NRRD, VTK structured points, and PNG and PNM images.  "
     "\"unu make -bs -1\" can read from DICOM files.  "
     "\"unu save \" can generate EPS files. "
     "Supported encodings are raw, ascii, hex, gzip, and bzip2.\n"
     );
  char par3[] = 
    ("\t\t\t\t"
     "Much of the functionality of unu derives from chaining multiple "
     "invocations of unu together with pipes (\"|\"), minimizing the "
     "need to save out intermediate files. For example, if "
     "\"data.raw.gz\" is a gzip'ed 256\tx\t256\tx\t80 volume of raw floats "
     "written from a PC, "
     "then the following will save to \"zsum.png\" a histogram "
     "equalized summation projection along the slowest axis:\n"
     );
  char par4[] = 
    ("\tunu make -i data.raw.gz -t float -s 256 256 80 "
     "-e gzip -en little \\\n "
     "  | unu project -a 2 -m sum \\\n "
     "  | unu heq -b 2000 -s 1 \\\n "
     "  | unu quantize -b 8 -o zsum.png"
     "\n"
     );
  /*
  char par5[] =
    ("\t\t\t\t"
     "Nrrd and unu were developed to fill a gap in existing software for "
     "handling image and volume datasets: generality of type and dimension, "
     "minimal overhead for getting data in and out, "
     "with a file format and data structure that represents important "
     "meta-information: sample spacing, cell vs. node centering, " 
     "per-axis text string labels, comments, etc.\n"
     );
  */
  char par6[] =
    ("\t\t\t\t"
     "If unu or nrrd repeatedly proves itself useful for your research, an "
     "acknowlegement to that effect in your publication would be greatly "
     "appreciated, such as (for LaTeX): "
     "\"Dataset processing performed with the {\\tt unu} tool "
     "(or the {\\tt nrrd} library), "
     "part of the {\\tt teem} toolkit available at "
     "{\\tt\t$<$http://www.cs.utah.edu/$\\sim$gk/teem$>$}\"\n "
     );
  char par7[] =
    ("\t\t\t\t"
     "Feedback, questions, requests welcome: gk@cs.utah.edu.\n"
     );

  fprintf(stderr, "\n");
  sprintf(buff, "--- unu: Utah Nrrd Utilities command-line interface ---");
  sprintf(fmt, "%%%ds\n",
	  (int)((hparm->columns-strlen(buff))/2 + strlen(buff) - 1));
  fprintf(stderr, fmt, buff);
  fprintf(stderr, "\n");

  _hestPrintStr(stderr, 1, 0, 78, par1, AIR_FALSE);
  _hestPrintStr(stderr, 1, 0, 78, par2, AIR_FALSE);
  _hestPrintStr(stderr, 1, 0, 78, par3, AIR_FALSE);
  _hestPrintStr(stderr, 2, 0, 78, par4, AIR_FALSE);
  /* _hestPrintStr(stderr, 1, 0, 78, par5, AIR_FALSE); */
  _hestPrintStr(stderr, 1, 0, 78, par6, AIR_FALSE);
  _hestPrintStr(stderr, 1, 0, 78, par7, AIR_FALSE);

  return 0;
}

UNRRDU_CMD(about, INFO);
